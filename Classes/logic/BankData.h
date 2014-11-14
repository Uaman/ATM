//developed by Lysenko Vladyslav
#pragma once;
#include <iostream>
#include "Account.h"
#include <vector> 
#include <string>
#include <map>
class BankData{
private:
    vector<Account> _accounts;
    map<string,double> _cardToAmount;
public:
	BankData(){};
	~BankData(){};
	//getters
	const vector<Account>& accounts()const {return _accounts;}
    const map<string,double>& getcardToAmount() const {return _cardToAmount;}
	//setters
    vector<Account>& accounts() {return _accounts;}
    map<string,double>& cardToAmount()  {return _cardToAmount;}
};
