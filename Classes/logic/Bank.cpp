#include "Bank.h"

const double& Bank::getAmoundByCard(const Operation& oc) {
   return DataStorage::getMoney(oc._accountFrom,oc._numberFrom);
}


bool Bank::withdrawAmoundFromCard(const Operation& oc){
    return (DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount) == true);
}


bool Bank::sendMoney(const Operation& oc){
   if(DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount)){
        DataStorage::putMoney((DataStorage::getAccountByCardNumber(oc._numberTo)),oc._numberTo,oc._amount);
        return true;
    }
    return false;
}


