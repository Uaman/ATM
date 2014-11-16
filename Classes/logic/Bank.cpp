//developed by Lysenko Vladyslav
#include "Bank.h"

//uses method from DataStorage class for getting money from card
const double& Bank::getAmoundByCard(const Operation& oc) {
   return DataStorage::getMoney(oc._accountFrom,oc._numberFrom);
}

//uses method from DataStorage class for withdrawing money from card
bool Bank::withdrawAmoundFromCard(const Operation& oc){
    return (DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount) == true);
}

//uses method from DataStorage class for snding money from one card to another
bool Bank::sendMoney(const Operation& oc){
   if(DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount)){
        DataStorage::putMoney((DataStorage::getAccountByCardNumber(oc._numberTo)),oc._numberTo,oc._amount);
        return true;
    }
    return false;
}


