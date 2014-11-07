#pragma once;
#include <iostream>
#include <vector> 
#include "Account.h"
#include "MD5.h"
using namespace std;
class DataStorage{
	private:
	   static vector<Account> _accounts;
	   static DataStorage _instance;
	   static vector<Account>::iterator Iter;
	   DataStorage(){};//
	   DataStorage(const DataStorage&){};//
	   DataStorage& operator=(const DataStorage&){};//
	public:
		static void initATM();
		static const DataStorage& DataStorage::Instance(){
			/*if(_instance==NULL)
				static DataStorage theSingleInstance;*/
			return _instance;
		}
		//static Account::Card getCard(const string& number);
		static const Account& getAccountByCard(const string& number,const string& password);
		static void putMoney(const Account& ac,const string&  number, double  amount);
		static void withdrawMoney(const Account& ac, const string&  number,const double& amount);
		static void addCard(const Account& ac,const string&  number, const string& pin);
		static   const vector<Account>& getAll(){return DataStorage::_accounts;};
};