#include "ATM.h"

//ATM

void ATM::startATM(){
    DataStorage::initATM();
    //method creates and opens main menu

}
void ATM::checkCard(){
    //takes this parameters from fields
    string name="1234567890123651";
    string password = "7561";

    /* getAccountByCard checks if card with given parameters exists in system,
        and if card exists method returns account which has this card/ else it returns empty account
    */

    _currentAccount = DataStorage::getAccountByCard(name,password);

    if(_currentAccount!=Account()){
        _inputCardNumber = name;

        /*//testing
        DataStorage::addCard(_currentAccount,"1780033889965431","8657");
        DataStorage::setExcessFunds(_currentAccount,"1780033889965431");
        DataStorage::putMoney(_currentAccount,"1334234234342212",46686);
        DataStorage::putMoney(_currentAccount,"1780033889965431",100);
        DataStorage::withdrawMoney(_currentAccount,"1334234234342212",1120);
        DataStorage::putMoney(_currentAccount,"4984654351484864",1120);

        //showing all accounts
        BankData data = DataStorage::getAll();
        vector<Account> vectAcc =data.accounts();
        vector<Account>::iterator Iter;
        for ( Iter = vectAcc.begin( ) ; Iter != vectAcc.end( ) ; Iter++ ){
            (*Iter).show();
            cout<<endl;
        }

        //showing all amounts
        BankData data1 = DataStorage::getAll();
        auto it = data1.cardToAmount().begin();
         while (it != data1.cardToAmount().end()) {
            cout << (*it).first << ": "
                 << (*it).second << endl;
            ++it;
         }
         cout<<endl;
         //getting amount of current card
         cout<<_inputCardNumber<<" : "<<data1.cardToAmount().find(_inputCardNumber)->second<<endl;
         //getting number of excess card of current account
         cout<<"excess card: "<<DataStorage::getAll().accountIdToExcessCard().find(_currentAccount.pointId())->second ;
         */

        //...... open window with actions
    }
}

ATM::ATM():_currentAccount(Account()),_inputCardNumber(""){
    return;
}

ATM::~ATM(){
    return;
}

//TR_Service

ATM::TR_Service::TR_Service(){
    //?
    return;
}
ATM::TR_Service::~TR_Service(){
    //?
    return;
}

//Transaction

ATM::TR_Service::Transaction::Transaction(const  byte& operCode,const double& amount, const string& date, const Account& from, const Account& to):
    _operCode(operCode), _amount(amount),_date(date),_from(from),_to(to){
        return;
}
ATM::TR_Service::Transaction::~Transaction(){
    return;
}
