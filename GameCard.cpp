
#include "GameCard.h"
#include <random>
#include <algorithm>

std::vector<GameCard*> GameCard::deck;

void GameCard::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g( rd() );
    
    std::shuffle( deck.begin(),deck.end(), g );
}

GameCard* GameCard::takeTopOfDeck() {
    GameCard* cardToReturn = *(deck.end());
    
    deck.erase( deck.end() );
    
    return cardToReturn;
}

void GameCard::putOnBottomOfDeck(GameCard* card) {
    deck.insert(deck.begin(), card);
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
