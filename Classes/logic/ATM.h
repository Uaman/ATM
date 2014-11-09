#pragma once;
#include <iostream>
#include <string>
#include "Account.h"
#include "DataStorage.h"
#include "../GUI/MenuStates.h"
using namespace std;
typedef unsigned char  byte;
class  ATM : public QObject{
    Q_OBJECT
    private:
        Account _currentAccount;
        string _inputCardNumber;
        MenuStates ms;
        class TR_Service;
        ATM(const ATM&);
        ATM& operator=(ATM&);
signals:
        void signal_accept_login();
    public:
        void startATM();
        bool checkCard();
        ATM();
        ~ATM();
public slots:
        void passwordChecker();

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
