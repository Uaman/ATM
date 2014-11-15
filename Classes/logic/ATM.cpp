//developed by Lysenko Vladyslav
#include "ATM.h"

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
    return;
}

void ATM::passwordChecker()
{
    if(checkCard())
    //if(true)
        ms.allowLogIn();
    else{
        QMessageBox::critical(0, "Log in error", "Incorrect card number or password!");
    }
}

ATM::~ATM(){
    return;
}

//
void ATM::getAmount(){
   Operation op(_currentAccount,_inputCardNumber,"",0);
   cout<<"amount = "<<Bank::getAmoundByCard(op)<<endl;
}

void ATM::withdrawMoney(){
    //amount from input
    double amount=10;
  if(!(Bank::withdrawAmoundFromCard(Operation(_currentAccount,_inputCardNumber,"",amount)))){
      QMessageBox::critical(0, "Withdraw error", "Insufficient amount of money!");
  }
}

void ATM::sendMoney(){
    //amount and card number from input
    double amount=10;
    string to = "4327463724623746";
    if(!Bank::sendMoney(Operation(_currentAccount,_inputCardNumber,to,amount))){
        QMessageBox::critical(0, "Sending error", "Insufficient amount of money on your card!");
    }
}




