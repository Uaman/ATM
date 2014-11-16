//developed by Lysenko Vladyslav
#include "Account.h"
int Account::_FreeId=0;
Account::Account(const  string& name, const  string& sername, const  string& bDate):_name(name),
    _sername(sername),_birthdate(bDate),_PointId(++_FreeId){
        return;
}
Account::Account(const Account& ac):_name(ac.name()),
    _sername(ac.sername()),_birthdate(ac.birthdate()),_cards(ac.cards()),_PointId(ac.pointId()){
        return;

}

Account::Account():_name(""),_sername(""),_birthdate(""),_PointId(++_FreeId){
    return;
}

Account& Account::operator=(const Account& ac){
    _name = ac.name();
    _sername = ac.sername();
    _birthdate = ac.birthdate();
    _PointId = ac.pointId();
    _cards = ac.cards();
    return *this;
};

Account::~Account(){
    return;
}

//returns a card by number given
Card& Account::getCardByNumber(const string& number){
    Card res("","");
    for(int i=0;i<static_cast<int>(_cards.size());i++){
            if(_cards[i].number()==number){
                return _cards[i];
            }
    }
    return res;
}

//inserts a new card to the account
void Account::insertCard(const string& number,const  string& password){
    (*this)._cards.push_back( Card(number,password));
}

bool operator==(const Account& ac1, const Account& ac2){
    return ac1.name()==ac2.name()&&ac1.birthdate()==ac2.birthdate()&&ac1.sername()==ac2.sername();
}

bool operator!=(const Account& ac1, const Account& ac2){
    return !(ac1==ac2);
}
