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
	 void setIdentifier(string _identifier);

	void toString();

protected:
	int number;
	string identifier;
    vector<string> tokenNames;
	bool checkIdentifier(string _identifier);
	 bool checkNumber(int _number);

};

