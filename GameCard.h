#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class GameCard
{
public:
	GameCard();
	GameCard(string _identifier);
	~GameCard();

    //what type of game card
	string getIdentifier();
	void setIdentifier(string _identifier);

    virtual void toString();

protected:
	string identifier;
};

