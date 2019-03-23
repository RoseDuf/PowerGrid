#pragma once
#include <string>
#include <iostream>

using namespace std;
class House
{
public:

    House();
    House(int _number, string _identifier);
    ~House();
    
    int getNumber();
    string getIndentifier();
    void setNumber(int _number);
    
    //type of game piece
    void setIdentifier(string _identifier);
    
    virtual void toString();
    
private:
    int number;
    string identifier;
	
};

