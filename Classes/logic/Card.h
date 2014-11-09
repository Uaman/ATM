//developed by Lysenko Vladyslav
#pragma once;
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Card{
    private:
        string  _number;
        string  _password;

        //~Card(){}
    public:
        Card();
        Card(const Card&);
        Card& operator=(Card&);
        Card(const string& number, const string& date);
        const string& number() const{return _number;}
        const string& password() const{return _password;}
        //just for testing
        void show();
};
