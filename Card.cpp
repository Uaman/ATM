#include "Card.h"

Card::Card():_number(""),_password(""),_amount(0){
	return;
}
Card::Card(const Card& card):_number(card.number()),_password(card.password()),_amount(card.amount()){
	return;
}

Card::Card(const  string& number, const  string& date):_number(number),_password(date),_amount(0){
	return;
}

Card& Card::operator=(Card& c){
	_number = c.number();
	_password = c.password();
	_amount = c.amount();
	return *this;
}

//just for testing
void Card::show(){
	cout<<"card number: "<<this->number()<<endl<<
		"amount: "<<this->amount()<<endl<<endl;		
}