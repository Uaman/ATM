//developed by Lysenko Vladyslav
#include "DataStorage.h"

DataStorage DataStorage::_instance;
BankData DataStorage::_data;

vector<BankData>::iterator DataStorage::Iter;

void DataStorage::initATM(){
    Account ac("Petro","Petrov","16.03.1984");

    _data.accounts().push_back(ac);
    _data.accounts().back().insertCard("1234567890123651",md5("7561"));
    _data.accounts().back().insertCard("4984654351484864",md5("5768"));
    _data.accounts().back().insertCard("1218998165132318",md5("3201"));

    _data.accountIdToExcessCard().insert(pair<int,string>(ac.pointId(),"0"));
    _data.cardToAmount().insert(pair<string,int>("1234567890123651",0));
    _data.cardToAmount().insert(pair<string,int>("4984654351484864",0));
    _data.cardToAmount().insert(pair<string,int>("1218998165132318",0));

    Account ac1("Ivan","Ivanov","27.05.1975");
    _data.accounts().push_back(ac1);
    _data.accounts().back().insertCard("4327463724623746",md5("1234"));
    _data.accounts().back().insertCard("1334234234342212",md5("9368"));
    _data.accounts().back().insertCard("9456452312334123",md5("9057"));

    _data.accountIdToExcessCard().insert(pair<int,string>(ac1.pointId(),"0"));
    _data.cardToAmount().insert(pair<string,int>("4327463724623746",0));
    _data.cardToAmount().insert(pair<string,int>("1334234234342212",0));
    _data.cardToAmount().insert(pair<string,int>("9456452312334123",0));

    Account ac2("Sergiy","Sergeev","22.11.1989");
    _data.accounts().push_back(ac2);
    _data.accounts().back().insertCard("1643234324234123",md5("1573"));
    _data.accounts().back().insertCard("9657433242341234",md5("9374"));
    _data.accounts().back().insertCard("1235234324124334",md5("2668"));

    _data.accountIdToExcessCard().insert(pair<int,string>(ac2.pointId(),"0"));
    _data.cardToAmount().insert(pair<string,int>("1643234324234123",0));
    _data.cardToAmount().insert(pair<string,int>("9657433242341234",0));
    _data.cardToAmount().insert(pair<string,int>("1235234324124334",0));

}

void DataStorage::addCard(const Account& ac,const string&  number, const string& pin){
    for(int i=0;i<DataStorage::_data.accounts().size();i++){
        if(DataStorage::_data.accounts()[i]==ac){
            DataStorage::_data.accounts()[i].insertCard(number,pin);
        }
    }
    _data.cardToAmount().insert(pair<string,int>(number,0));
}

void DataStorage::putMoney(const Account& ac,const string&  number, double  amount){
    for(int i=0;i<DataStorage::_data.accounts().size();i++){
        if(DataStorage::_data.accounts()[i]==ac){
            //DataStorage::_data.cardToAmount().find(number)->second+=amount;
            //
             auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                  if((*it).first==number)
                      (*it).second+=amount;
                        ++it;
              }

        }
    }
}
void DataStorage::withdrawMoney(const Account& ac,const string&  number,const double& amount){
    for(int i=0;i<DataStorage::_data.accounts().size();i++){
        if(DataStorage::_data.accounts()[i]==ac){
            //DataStorage::_data.cardToAmount().find(number)->second-=amount;
            //
            auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                  if((*it).first==number)
                      (*it).second+=amount;
                        ++it;
              }
        }
    }
}

//TODO
const Account*  DataStorage::getAccountByCard(const string &number,const string& password){
    for(int i=0;i<DataStorage::_data.accounts().size();i++){
        for(int j=0;j<DataStorage::_data.accounts()[i].cards().size();j++){
            if((DataStorage::_data.accounts()[i].cards()[j].number()==number)&&(DataStorage::_data.accounts()[i].cards()[j].password()==md5(password)))
                return &DataStorage::_data.accounts()[i];
        }
    }

    return new Account();
}

void DataStorage::setExcessFunds(const Account& ac,const string& number){
    for(int i=0;i<DataStorage::_data.accounts().size();i++){
        for(int j=0;j<DataStorage::_data.accounts()[i].cards().size();j++){
            if(DataStorage::_data.accounts()[i]==ac){
                //(DataStorage::_data.accountIdToExcessCard().find(ac.pointId())->second) = number;
                //
                auto it = _data.accountIdToExcessCard().begin();
                 while (it != _data.accountIdToExcessCard().end()) {
                    if((*it).first==ac.pointId()){
                        (*it).second = number;
                  }
                        ++it;
              }
            }
        }
    }
}

/*
auto it = _data.cardToAmount().begin();
              while (it != _data.cardToAmount().end()) {
                cout << (*it).first << ": "
                     << (*it).second << endl;
                ++it;
              }


*/
