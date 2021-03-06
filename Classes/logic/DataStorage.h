//developed by Lysenko Vladyslav
#pragma once;
#include <iostream>
#include <vector>
#include <QString>
#include "Account.h"
#include "BankData.h"
#include "MD5.h"
using namespace std;
class DataStorage{
    private:
       static DataStorage _instance;
       static BankData _data;
       static vector<BankData>::iterator Iter;
       DataStorage(){}//
       DataStorage(const DataStorage&){}//
       DataStorage& operator=(const DataStorage&){}//
    public:
        static void initATM();
        static const DataStorage& DataStorage::Instance(){
            /*if(_instance==NULL)
                static DataStorage theSingleInstance;*/
            return _instance;
        }

        static const double& getMoney(const Account& ac,const string&  number);
        static const Account* getAccountByCard(const string& number,const string& password);
        static const Account* getAccountByCardNumber(const string& number);
        static void putMoney(const Account& ac,const string&  number, double  amount);
        static bool withdrawMoney(const Account& ac, const string&  number,const double& amount);
        static void addCard(const Account& ac,const string&  number, const string& pin);
        //static   const BankData& getAll(){return DataStorage::_data;}

};
