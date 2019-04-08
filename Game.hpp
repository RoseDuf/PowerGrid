#ifndef GAME_HPP_
#define GAME_HPP_

#include "Player.hpp"
//#include "GameState.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Game {

public:
	vector<Player*> game_players;

	Game();
	Game(vector <Player*> players);

	//Task 3
	void reversePlayerOrder(vector<Player*> players);
	void buyingResources();
	void buildingCities();
	void dashboard(Player* p);

	//Show possessions of each player at end of Phase 4








};

#endif
