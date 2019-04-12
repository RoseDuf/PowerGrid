
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Game.h"
#include "Stats.h"
#include "GameplayDirector.h"
#include "PowerGridBuilder.h"
#include "Gameplay.h"

using namespace std;
using namespace HelperFunctions;


int main()
{
	
	Game *game = new Game();


	//GameplayDirector director;
	//director.createGameplay(players, map, phase);

	Stats *stats = new Stats(game);
	game->play();
	//TO DO :
	
	//delete the pointers
	//implement the destructor of game to delete the powerplant pointers, players...
	
	

	return 0;
}

