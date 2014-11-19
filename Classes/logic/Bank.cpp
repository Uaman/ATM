//developed by Lysenko Vladyslav
#include "Bank.h"

//Bank Bank::_instance;
//uses method from DataStorage class for getting money from card
const double& Bank::getAmoundByCard(const Operation& oc) {
   return DataStorage::getMoney(oc._accountFrom,oc._numberFrom);
}

//uses method from DataStorage class for withdrawing money from card
int Bank::withdrawAmoundFromCard(const Operation& oc){
    if(oc._amount<=0)
        return 1;
    if (DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount));
        return 3;
    if (!DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount));
        return 4;

}

//uses method from DataStorage class for snding money from one card to another
int Bank::sendMoney(const Operation& oc){
   Account ac = (*DataStorage::getAccountByCardNumber(oc._numberTo));
   if(ac==Account()){
       return 2;
   }
   if(oc._amount<=0){
       return 4;
   }
   if(oc._numberFrom==oc._numberTo){
        return 5;
   }
   else if(DataStorage::withdrawMoney(oc._accountFrom,oc._numberFrom,oc._amount)){
        DataStorage::putMoney(ac,oc._numberTo,oc._amount);
        return 1;
    }
    return 3;
}


