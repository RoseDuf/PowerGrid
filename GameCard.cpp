
#include "GameCard.h"
#include <random>
#include <algorithm>

std::list<GameCard*> GameCard::deck;

void GameCard::shuffleDeck() {
    srand(time(0));
    random_shuffle( deck.begin(),deck.end() );
}

GameCard* GameCard::takeTopGameCard() {
    GameCard* cardToReturn = *(deck.end());
    
    deck.remove( *(deck.end()) );
    
    return cardToReturn;
}

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
