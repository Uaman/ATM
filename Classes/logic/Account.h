//developed by Lysenko Vladyslav
#pragma once;
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
using namespace std;

class Account{
//public:
    //class Card;
private:
    //class Card;
    vector<Card> _cards;
    vector <Card>::iterator Iter;
    static int _FreeId;
    int _PointId;
    string _name;
    string _sername;
    string _birthdate;
public:
    Account& operator=(const Account&);
    inline const vector<Card>& getCards() const{ return _cards;};
    void insertCard(const string& number,const  string& password);
    Card& getCardByNumber(const string& number); //could be problem because of returning of reference
    ~Account();
    Account();
    Account(const Account& ac);
    Account(const  string& name, const  string& sername, const  string& bDate);
    const string& name() const{return _name;}
    const string& sername() const{return _sername;}
    const string& birthdate() const{return _birthdate;}
    const vector<Card>& cards() const{return _cards;}
    const int& pointId() const {return _PointId;}
    //just for testing
    void show();
};

bool operator==(const Account&, const Account&);
bool operator!=(const Account&, const Account&);
