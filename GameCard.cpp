
#include "GameCard.h"
#include <random>
#include <algorithm>
#include "PowerPlant.hpp"

using namespace std;

std::vector<GameCard*> GameCard::deck;
bool GameCard::deckInitialized = false;

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

void GameCard::initializeDeck() {
    if(deckInitialized == false) {
        //  PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed);

        PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
        PowerPlant *p2 = new PowerPlant(4, 1, 2, 0, 0, 0);
        PowerPlant *p3 = new PowerPlant(5, 1, 2, 2, 0, 0);
        PowerPlant *p4 = new PowerPlant(6, 1, 0, 0, 1, 0);
        PowerPlant *p5 = new PowerPlant(7, 2, 0, 3, 0, 0);
        PowerPlant *p6 = new PowerPlant(8, 2, 3, 0, 0, 0);
        PowerPlant *p7 = new PowerPlant(9, 1, 0, 1, 0, 0);
        PowerPlant *p8 = new PowerPlant(10, 2, 2, 0, 0, 0);
        PowerPlant *p9 = new PowerPlant(11, 2, 0, 0, 0, 1);
        PowerPlant *p10 = new PowerPlant(12, 2, 2, 2, 0, 0);
        PowerPlant *p11 = new PowerPlant(13, 1, 0, 0, 0, 0);
        PowerPlant *p12 = new PowerPlant(14, 2, 0, 0, 2, 0);
        PowerPlant *p13 = new PowerPlant(15, 3, 2, 0, 0, 0);
        PowerPlant *p14 = new PowerPlant(16, 3, 0, 2, 0, 0);
        PowerPlant *p15 = new PowerPlant(17, 2, 0, 0, 0, 1);
        PowerPlant *p16 = new PowerPlant(18, 2, 0, 0, 0, 0);
        PowerPlant *p17 = new PowerPlant(19, 3, 0, 0, 2, 0);
        PowerPlant *p18 = new PowerPlant(20, 5, 3, 0, 0, 0);
        PowerPlant *p19 = new PowerPlant(21, 4, 2, 2, 0, 0);
        PowerPlant *p20 = new PowerPlant(22, 2, 0, 0, 0, 0);
        PowerPlant *p21 = new PowerPlant(23, 3, 0, 0, 0, 1);
        PowerPlant *p22 = new PowerPlant(24, 4, 0, 0, 2, 0);
        PowerPlant *p23 = new PowerPlant(25, 5, 2, 0, 0, 0);
        PowerPlant *p24 = new PowerPlant(26, 5, 0, 2, 0, 0);
        PowerPlant *p25 = new PowerPlant(27, 3, 0, 0, 0, 0);
        PowerPlant *p26 = new PowerPlant(28, 4, 0, 0, 0, 1);
        PowerPlant *p27 = new PowerPlant(29, 4, 2, 2, 0, 0);
        PowerPlant *p28 = new PowerPlant(30, 6, 0, 0, 3, 0);
        PowerPlant *p29 = new PowerPlant(31, 6, 3, 0, 0, 0);
        PowerPlant *p30 = new PowerPlant(32, 6, 0, 3, 0, 0);
        PowerPlant *p31 = new PowerPlant(33, 4, 0, 0, 0, 0);
        PowerPlant *p32 = new PowerPlant(34, 5, 0, 0, 0, 1);
        PowerPlant *p33 = new PowerPlant(35, 5, 0, 1, 0, 0);
        PowerPlant *p34 = new PowerPlant(36, 7, 3, 0, 0, 0);
        PowerPlant *p35 = new PowerPlant(37, 4, 0, 0, 0, 0);
        PowerPlant *p36 = new PowerPlant(38, 7, 0, 0, 3, 0);
        PowerPlant *p37 = new PowerPlant(39, 6, 0, 0, 0, 1);
        PowerPlant *p38 = new PowerPlant(40, 6, 0, 2, 0, 0);
        PowerPlant *p39 = new PowerPlant(42, 6, 2, 0, 0, 0);
        PowerPlant *p40 = new PowerPlant(44, 5, 0, 0, 0, 0);
        PowerPlant *p41 = new PowerPlant(46, 7, 3, 3, 0, 0);
        PowerPlant *p42 = new PowerPlant(50, 6, 0, 0, 0, 0);
        GameCard* s3 = new GameCard("s3");
        
        deck.push_back(p1);
        deck.push_back(p2);
        deck.push_back(p3);
        deck.push_back(p4);
        deck.push_back(p5);
        deck.push_back(p6);
        deck.push_back(p7);
        deck.push_back(p8);
        deck.push_back(p9);
        deck.push_back(p10);
        deck.push_back(p11);
        deck.push_back(p12);
        // deck.push_back(p13); intentionally omitted (because it will be added in the end (so that it's at the top of the deck))
        deck.push_back(p14);
        deck.push_back(p15);
        deck.push_back(p16);
        deck.push_back(p17);
        deck.push_back(p18);
        deck.push_back(p19);
        deck.push_back(p20);
        deck.push_back(p21);
        deck.push_back(p22);
        deck.push_back(p23);
        deck.push_back(p24);
        deck.push_back(p25);
        deck.push_back(p26);
        deck.push_back(p27);
        deck.push_back(p28);
        deck.push_back(p29);
        deck.push_back(p30);
        deck.push_back(p31);
        deck.push_back(p23);
        deck.push_back(p33);
        deck.push_back(p34);
        deck.push_back(p35);
        deck.push_back(p36);
        deck.push_back(p37);
        deck.push_back(p38);
        deck.push_back(p39);
        deck.push_back(p40);
        deck.push_back(p41);
        deck.push_back(p42);
            
        shuffleDeck();
        
        putOnBottomOfDeck(s3);
        deck.push_back(p13); // this is intentionally at the end (so that it's at the top of the deck)
        deckInitialized = true;
    }
    else {
        // throw some kind of already initialized exception or something
    }
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
