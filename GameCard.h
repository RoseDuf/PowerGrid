
#ifndef GAMECARD_HPP_
#define GAMECARD_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <list>

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
    
    static void shuffleDeck();
    
    static GameCard* takeTopOfDeck();
    
private:
    static std::list<GameCard*> deck;

protected:
	string identifier;
};

#endif
