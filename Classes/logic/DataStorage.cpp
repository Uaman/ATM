//developed by Lysenko Vladyslav
#include "DataStorage.h"

DataStorage DataStorage::_instance;
BankData DataStorage::_data;

vector<BankData>::iterator DataStorage::Iter;

//creates accounts and cards in the system
void DataStorage::initATM(){
    Account ac("Petro","Petrov","16.03.1984");
    _data.accounts().push_back(ac);
    _data.accounts().back().insertCard("1234567890123651",md5("7561"));
    _data.accounts().back().insertCard("4984654351484864",md5("5768"));
    _data.accounts().back().insertCard("1218998165132318",md5("3201"));

    _data.cardToAmount().insert(pair<string,int>("1234567890123651",1500));
    _data.cardToAmount().insert(pair<string,int>("4984654351484864",0));
    _data.cardToAmount().insert(pair<string,int>("1218998165132318",210));

    Account ac1("Ivan","Ivanov","27.05.1975");
    _data.accounts().push_back(ac1);
    _data.accounts().back().insertCard("4327463724623746",md5("1234"));
    _data.accounts().back().insertCard("1334234234342212",md5("9368"));
    _data.accounts().back().insertCard("9456452312334123",md5("9057"));


    _data.cardToAmount().insert(pair<string,int>("4327463724623746",350));
    _data.cardToAmount().insert(pair<string,int>("1334234234342212",0));
    _data.cardToAmount().insert(pair<string,int>("9456452312334123",12000));

    Account ac2("Sergiy","Sergeev","22.11.1989");
    _data.accounts().push_back(ac2);
    _data.accounts().back().insertCard("1643234324234123",md5("1573"));
    _data.accounts().back().insertCard("9657433242341234",md5("9374"));
    _data.accounts().back().insertCard("1235234324124334",md5("2668"));


    _data.cardToAmount().insert(pair<string,int>("1643234324234123",20));
    _data.cardToAmount().insert(pair<string,int>("9657433242341234",150));
    _data.cardToAmount().insert(pair<string,int>("1235234324124334",90));

}

//method adds a new card to account
void DataStorage::addCard(const Account& ac,const string&  number, const string& pin){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        if(DataStorage::_data.accounts()[i]==ac){
            DataStorage::_data.accounts()[i].insertCard(number,pin);
        }
    }
    _data.cardToAmount().insert(pair<string,int>(number,0));
}

//method puts money on the card
void DataStorage::putMoney(const Account& ac,const string&  number, double  amount){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        if(DataStorage::_data.accounts()[i]==ac){
             auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                  if((*it).first==number)
                      (*it).second+=amount;
                        ++it;
              }

        }
    }
}

//method withdraws money from the card if there is enough money on the card
bool DataStorage::withdrawMoney(const Account& ac,const string&  number,const double& amount){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        if(DataStorage::_data.accounts()[i]==ac){
            auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                  if((*it).first==number){
                      if((*it).second>=amount){
                         (*it).second-=amount;
                          return true;
                      }

                  }
                        ++it;
              }
        }
    }
    return false;
}


//method returns account if card with given password and number exists
const Account*  DataStorage::getAccountByCard(const string &number,const string& password){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        for(int j=0;j<static_cast<int>(DataStorage::_data.accounts()[i].cards().size());j++){
            if((DataStorage::_data.accounts()[i].cards()[j].number()==number)&&(DataStorage::_data.accounts()[i].cards()[j].password()==md5(password)))
                return &DataStorage::_data.accounts()[i];
        }
    }
    return new Account();
}

//returns account by card number
const Account* DataStorage::getAccountByCardNumber(const string& number){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        for(int j=0;j<static_cast<int>(DataStorage::_data.accounts()[i].cards().size());j++){
            if((DataStorage::_data.accounts()[i].cards()[j].number()==number))
                return (&DataStorage::_data.accounts()[i]);
        }
    }
    return new Account();
}

//returns money of the card
const double& DataStorage::getMoney(const Account& ac,const string&  number){
    for(int i=0;i<static_cast<int>(DataStorage::_data.accounts().size());i++){
        if(DataStorage::_data.accounts()[i]==ac){
             auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                  if((*it).first==number)
                      return static_cast<double>((*it).second);
                        ++it;
              }

        }
    }


}
