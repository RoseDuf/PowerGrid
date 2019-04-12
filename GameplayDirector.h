#pragma once
#include "GameplayBuilder.h"
#include "Gameplay.h"

//GameplayDirector builds Gameplay object step-by-step.
//Tells builder to build in a specific order.

class GameplayDirector {

	GameplayBuilder* builder;

public:

	//Need to take in the name of a Map, a vector of players (take this from Game functions), the phase of the game
	//Gameplay will only be called if players want to save the game/exit the game
	Gameplay* createGameplay(vector<Player> &players, string& map, string& phase) {			//remember phase is for example: buying resources, buying cities, etc.
		builder->buildPlayers(players);
		builder->buildMap(map);
		builder->buildPhase(phase);

		return builder->getGameplay();
	}
};