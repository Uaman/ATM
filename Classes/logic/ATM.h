#pragma once;
#include <iostream>
#include <string>
#include "Account.h"
#include "DataStorage.h"
using namespace std;
typedef unsigned char  byte;
class  ATM{
    private:
    //	Menu menu;

        /*
            this two parameters need for working with methods from
            DataStorage class.
        */
        Account _currentAccount;
        string _inputCardNumber;

        class TR_Service;
        ATM(const ATM&);
        ATM& operator=(ATM&);
    public:
        void startATM();
        void checkCard();
        ATM();
        ~ATM();
};


class  ATM::TR_Service{
    private:
        class Transaction;
        //Action action;
        const Transaction& createTransaction();
        void doOper(const Transaction& transaction);
        TR_Service(const TR_Service&);
        TR_Service& operator=( const TR_Service&);
    public:
        TR_Service();
        ~TR_Service();
 };


class  ATM::TR_Service::Transaction{
    friend class Operation;
    private:
        byte _operCode;
        string _date;
        double _amount;
        Account _from , _to;
        Transaction(const Transaction&);
        Transaction& operator=(const Transaction&);
    public:
        Transaction(const  byte&,const double& , const string&, const Account&, const Account&);
        ~Transaction();
};
