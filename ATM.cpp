#include "ATM.h"

//ATM

void ATM::startATM(){
	DataStorage::initATM();
	//method creates and opens main menu

}
void ATM::checkCard(){
	//takes this parameters from fields
	string name="1234567890123651";
	string password = "7561";

	/* getAccountByCard checks if card with given parameters exists in system,
		and if card exists method returns account which has this card/ else it returns empty account
	*/
	_currentAccount = DataStorage::getAccountByCard(name,password);

	if(_currentAccount!=Account()){
		_inputCardNumber = name;
		//...... open window with actions
	}
}

ATM::ATM():_currentAccount(Account()),_inputCardNumber(""){
	return;
}

ATM::~ATM(){
	return;
}

//TR_Service

ATM::TR_Service::TR_Service(){
	//?
	return;
}
ATM::TR_Service::~TR_Service(){
	//?
	return;
}

//Transaction

ATM::TR_Service::Transaction::Transaction(const  byte& operCode,const double& amount, const string& date, const Account& from, const Account& to):
	_operCode(operCode), _amount(amount),_date(date),_from(from),_to(to){
		return;
}
ATM::TR_Service::Transaction::~Transaction(){
	return;
}