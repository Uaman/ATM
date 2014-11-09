#pragma once;
#include <iostream>
#include "Account.h"
#include <vector> 
#include <string>
#include <map>
class BankData{
private:
    vector<Account> _accounts;
	map<int,string> _accountIdToExcessCard;
	map<string,double> _cardToAmount;
public:
	BankData(){};
	~BankData(){};
	//getters
	const vector<Account>& accounts()const {return _accounts;}
	const map<int,string>& accountIdToExcessCard() const {return _accountIdToExcessCard;}
	const map<string,double>& getcardToAmount() const {return _cardToAmount;}
	//setters
    vector<Account>& accounts() {return _accounts;}
    map<int,string>&  accountIdToExcessCard()  {return _accountIdToExcessCard;}
    map<string,double>& cardToAmount()  {return _cardToAmount;}
};