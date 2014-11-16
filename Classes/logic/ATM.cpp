//developed by Lysenko Vladyslav
#include "ATM.h"
#include <QDebug>

//ATM
void ATM::startATM(){
    DataStorage::initATM();
    ms._window->show();
    //method creates and opens main menu
}
bool ATM::checkCard(){
    string name =  ms.cardNumber();
    string password = ms.password();

    cout<<name<<" "<<password;
    _currentAccount = (*DataStorage::getAccountByCard(name,password));

    if(_currentAccount!=Account()){
        _inputCardNumber = name;

      /*  getAmount();
        withdrawMoney();
        getAmount();
        sendMoney();
        cout<<"After: "<<DataStorage::getMoney(DataStorage::getAccountByCardNumber("4327463724623746")
                              ,"4327463724623746");*/
         return true;
    }
    return false;
}

ATM::ATM():_currentAccount(Account()),_inputCardNumber(""){
    connect(&ms,SIGNAL(signal_try_password()),SLOT(passwordChecker()));
    connect(&ms,SIGNAL(getMoneyOnScreen()),SLOT(getMoneyOnScreen()));
    connect(&ms,SIGNAL(takeMoney()),SLOT(takeMoneySlot()));
    return;
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
    //if(true)
    if(checkCard())
        ms.allowLogIn();
    else{
        QMessageBox::critical(0, "Log in error", "Incorrect card number or password!");
    }
}

ATM::~ATM(){
    return;
}

//
const double& ATM::getAmount(){
   Operation op(_currentAccount,_inputCardNumber,"",0);
   return Bank::getAmoundByCard(op);
}

void ATM::withdrawMoney(double sum){
    //amount from input
    //double amount=10;
    Bank::withdrawAmoundFromCard(Operation(_currentAccount,_inputCardNumber,"",sum));
}

void ATM::sendMoney(){
    //amount and card number from input
    double amount=10;
    string to = "4327463724623746";
    Bank::sendMoney(Operation(_currentAccount,_inputCardNumber,to,amount));
}




