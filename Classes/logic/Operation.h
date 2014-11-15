//developed by Lysenko Vladyslav
#ifndef OPERATION_H
#define OPERATION_H
#include "Account.h"
#include "Bank.h"
class  Operation{
    friend class Bank;
       private:
         double _amount;
         Account _accountFrom;
         string _numberFrom , _numberTo;
         Operation(const Operation&){};
         Operation& operator=(const Operation&);
     public:
         Operation(){};
         ~Operation(){};
         Operation(Account&,const string&,const string&,const double& );
 };


#endif // OPERATION_H
