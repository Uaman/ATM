//developed by Lysenko Vladyslav
#pragma once;
#include <iostream>
#include <string>
#include "Account.h"
#include "DataStorage.h"
#include "Bank.h"
#include "Operation.h"
#include "../GUI/MenuStates.h"
#include <QMessageBox>
using namespace std;
typedef unsigned char  byte;
class  ATM : public QObject{
    Q_OBJECT
    friend class Bank;
    private:
        Account _currentAccount;
        string _inputCardNumber;
        MenuStates ms;
        //class Operation;
        ATM(const ATM&);
        ATM& operator=(ATM&);
signals:
        void signal_accept_login();
    public:
        void startATM();
        bool checkCard();
        ATM();
        ~ATM();
        const double &getAmount();
        void withdrawMoney(double sum);
        void sendMoney(QString to,double amount);
public slots:
        void sendMoneyOnCard();
        void takeMoneySlot();
        void passwordChecker();
        void getMoneyOnScreen();
        void logOut();
};

//class  ATM::Operation{
//       private:
//         double _amount;
//         Account _accountFrom;
//         string _numberFrom , _numberTo;
//         Operation(const Operation&);
//         Operation& operator=(const Operation&);
//         ~Operation();
//       public:
//         Operation(Account&,const string&,const string&,const double& );
//  };



