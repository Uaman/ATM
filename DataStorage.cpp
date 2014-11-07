#include "DataStorage.h"

DataStorage DataStorage::_instance;
vector<Account> DataStorage::_accounts;

vector<Account>::iterator DataStorage::Iter;

void DataStorage::initATM(){
	Account ac("Petro","Petrov","16.03.1984");
	_accounts.push_back(ac);
	_accounts.back().insertCard("1234567890123651",md5("7561"));
	_accounts.back().insertCard("4984654351484864",md5("5768"));
	_accounts.back().insertCard("1218998165132318",md5("3201"));

	Account ac1("Ivan","Ivanov","27.05.1975");
	_accounts.push_back(ac1);
	_accounts.back().insertCard("4327463724623746",md5("1234"));
	_accounts.back().insertCard("1334234234342212",md5("9368"));
	_accounts.back().insertCard("9456452312334123",md5("9057"));

	Account ac2("Sergiy","Sergeev","22.11.1989");
	_accounts.push_back(ac2);
	_accounts.back().insertCard("1643234324234123",md5("1573"));
	_accounts.back().insertCard("9657433242341234",md5("9374"));
	_accounts.back().insertCard("1235234324124334",md5("2668"));

}
void DataStorage::addCard(const Account& ac,const string&  number, const string& pin){
	for(int i=0;i<DataStorage::_accounts.size();i++){
		if(_accounts[i]==ac){
			_accounts[i].insertCard(number,pin);
		}
	}
}

void DataStorage::putMoney(const Account& ac,const string&  number, double  amount){
	for(int i=0;i<DataStorage::_accounts.size();i++){
		if(_accounts[i]==ac){
			_accounts[i].getCardByNumber(number).changeAmount()+=amount;
		}
	}
	
}
void DataStorage::withdrawMoney(const Account& ac,const string&  number,const double& amount){
	for(int i=0;i<DataStorage::_accounts.size();i++){
		if(_accounts[i]==ac){
			if(_accounts[i].getCardByNumber(number).amount()>=amount)
				_accounts[i].getCardByNumber(number).changeAmount()-=amount;
		}
	}
}

const Account&  DataStorage::getAccountByCard(const string &number,const string& password){
	for(int i=0;i<DataStorage::_accounts.size();i++){
		for(int j=0;j<_accounts[i].cards().size();j++){
			if((_accounts[i].cards()[j].number()==number)&&(_accounts[i].cards()[j].password()==md5(password)))
				return _accounts[i];
		}
	}
	return Account();
}

