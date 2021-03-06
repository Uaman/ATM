//developed by Lysenko Vladyslav
#include "ATM.h"
#include <QDebug>

//method creates and opens main menu and inits atm data
void ATM::startATM(){
    DataStorage::initATM();
    ms._window->show();
}

//method checks if card exists in the system and ints current accound and input card
bool ATM::checkCard(){
    string name =  ms.cardNumber();
    string password = ms.password();
     _currentAccount = (*DataStorage::getAccountByCard(name,password));

    if(_currentAccount!=Account()){
        _inputCardNumber = name;
        return true;
    }
    return false;
}


ATM::ATM():_currentAccount(Account()),_inputCardNumber(""){
    connect(&ms,SIGNAL(signal_try_password()),SLOT(passwordChecker()));
    connect(&ms,SIGNAL(getMoneyOnScreen()),SLOT(getMoneyOnScreen()));
    connect(&ms,SIGNAL(takeMoney()),SLOT(takeMoneySlot()));
    connect(&ms,SIGNAL(sendMoney()),SLOT(sendMoneyOnCard()));
    connect(&ms,SIGNAL(signal_Log_out()),SLOT(logOut()));
    return;
}

//Log out slot
void ATM::logOut()
{
    return;
}

//slot sending money on card
void ATM::sendMoneyOnCard()
{
    sendMoney(ms.getCardToSend(),ms.getMoneyToSend());
}

//taking money from _currentAccount card
void ATM::takeMoneySlot()
{
     withdrawMoney(ms.getTakingOutSum());
}

//getMoney from store and set on screen
void ATM::getMoneyOnScreen()
{
    //QDebug(st.toLatin1());
    ms.setCurrentMoney(QString::number(getAmount()));
}

void ATM::passwordChecker()
{
    if(checkCard())
        ms.allowLogIn();
    else{
        QMessageBox::critical(0, "Log in error", "Incorrect card number or password!");
    }
}

ATM::~ATM(){
    return;
}

//creates operation and calls method from Bank for getting amount
const double& ATM::getAmount(){
   Operation op(_currentAccount,_inputCardNumber,"",0);
   return Bank::getAmoundByCard(op);
}

//creates operation and calls method from Bank for withdrawing amount
void ATM::withdrawMoney(double sum){
    //amount from input
    int code =  Bank::withdrawAmoundFromCard(Operation(_currentAccount,_inputCardNumber,"",sum));
    switch(code){
        case 1:
            QMessageBox::critical(0, "Withdraw error", "Amount must be positive!");
            break;
        case 3:
            ms.onSuccssesfulScreen();
            break;
        case 4:
            QMessageBox::critical(0, "Withdraw error", "Insufficient amount of money!");
            break;
        default:
            break;
    }

 }
//creates operation and calls method from Bank for sending amount
void ATM::sendMoney(QString to,double amount){
    int code = Bank::sendMoney(Operation(_currentAccount,_inputCardNumber,to.toStdString(),amount));
    switch(code){
        case 1:
           ms.onSuccssesfulScreen();
           break;
        case 2:
           QMessageBox::critical(0, "Sending error", "Incorrect card number of recipient!");
           break;
        case 3:
           QMessageBox::critical(0, "Sending error", "Insufficient amount of money on your card!");
           break;
        case 4:
           QMessageBox::critical(0, "Sending error", "Amount must be positive!");
           break;
        case 5:
           QMessageBox::critical(0, "Sending error", "You can not send to your card!");
           break;
        default:
           break;
    }
}




