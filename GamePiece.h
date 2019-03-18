#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class GamePiece
{
public:
	GamePiece();
	GamePiece(int _number, string _identifier);
	~GamePiece();

	 int getNumber();
	 string getIndentifier();
	 void setNumber(int _number);
    
    //type of game piece
	 void setIdentifier(string _identifier);

    virtual void toString();

protected:
	int number;
	string identifier;
    
    //colors for  House and type for Ressource Token, used in checkIdentifier
    vector<string> tokenNames;
	bool checkIdentifier(string _identifier);
    bool checkNumber(int _number);

};

