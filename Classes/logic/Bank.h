//developed by Lysenko Vladyslav
#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include "Operation.h"
#include "DataStorage.h"
class Operation;
class Bank{
private:
    static Bank _instance;
    Bank(const Bank&);
    Bank& operator=(Bank&);
public:
    Bank();
    ~Bank();
    static const Bank& Bank::Instance(){
        /*if(_instance==NULL)
            static Bank theSingleInstance;*/
        return _instance;
    }
  static const double& getAmoundByCard(const Operation&);
  static bool withdrawAmoundFromCard(const Operation& oc);
  static bool sendMoney(const Operation& oc);
};

#endif // BANK_H

