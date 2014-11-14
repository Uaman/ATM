//developed by Lysenko Vladyslav
#include "Card.h"

Card::Card():_number(""),_password(""){
    return;
}
Card::Card(const Card& card):_number(card.number()),_password(card.password()){
    return;
}

Card::Card(const  string& number, const  string& date):_number(number),_password(date){
    return;
}

Card& Card::operator=(Card& c){
    _number = c.number();
    _password = c.password();
    return *this;
}

//just for testing
void Card::show(){
    cout<<"card number: "<<this->number()<<endl;
}
