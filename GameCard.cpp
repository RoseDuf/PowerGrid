#include "GameCard.h"

GameCard::GameCard()
{
}

GameCard::GameCard(string _identifier)
{
	identifier = _identifier;
}

GameCard::~GameCard()
{
	// TO DO
}

string GameCard::getIdentifier()
{
	return identifier;
}

void GameCard::setIdentifier(string _identifier)
{
	identifier = _identifier;
}

void GameCard::toString()
{
	cout << "Information about game card: " << identifier << endl;
}