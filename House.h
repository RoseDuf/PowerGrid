#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class House
{
public:
	House();
    House(string _identifier, int _num);
	~House();

    int getNumber();
    string getIndentifier();
    void setNumber(int _number);
    
    //type of game piece
    void setIdentifier(string _identifier);
    void toString();


private:
    int number;
    string identifier;
};

