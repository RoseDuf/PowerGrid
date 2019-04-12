#pragma once
#include "Gameplay.h"

/*BUILDER DESIGN PATTERN:

//We are using a GamePlayBuilder design pattern because we want to have a more
simple way of creating a complex object (Game), which is made up of many complex objects.
The objects that make up GamePlay themselves are dependent on each other.
The Builder design pattern creates an organized step-by-step way of creating the complex
GamePlay object.

Designed based off Builder Pattern template here:  https://github.com/7yadavrupesh/designpattern/blob/master/Builder%20Design%20Pattern/Builder%20Design%20Pattern%20In%20C%2B%2B.cpp


*/


using namespace std;

class GameplayBuilder {

protected:
	Gameplay* g1;

public:

	//creating pure virtual functions
	virtual void createGameplay(vector<Player*>& players, string map, string phase) = 0;
	virtual void buildPlayers(vector<Player*>& players) = 0;
	virtual void buildMap(string map) = 0;
	virtual void buildPhase(string phase) = 0;


	//virtual ~GameplayBuilder(){}

	Gameplay* getGameplay() { return g1; }


};