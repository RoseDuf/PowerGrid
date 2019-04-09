
#ifndef GAMECARD_HPP_
#define GAMECARD_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <list>

class GameCard
{
public:
	GameCard();
	GameCard(std::string _identifier);
	~GameCard();

    //what type of game card
	std::string getIdentifier();
	void setIdentifier(std::string _identifier);

    virtual void toString();
    
    static void shuffleDeck();
    
    static GameCard* takeTopOfDeck();
    
    static void putOnBottomOfDeck(GameCard* card);
    
private:
    static std::vector<GameCard*> deck;

protected:
	std::string identifier;
};

#endif
