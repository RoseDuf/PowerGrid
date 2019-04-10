#pragma once

#include <iostream>
#include <algorithm>
#include <random>
#include <ctype.h>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "Market.hpp"
#include "Game.h"
#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;
using namespace std;


class Game {

public:
	

	Game();
	//Game(vector <Player*> players);

	/*
	void reversePlayerOrder(vector<Player*> players);
	void buyingResources();
	void buildingCities();
	*/
	void dashboard(Player* p);

	//void phase1_determinePlayerOrder(vector<Player*> &players, int round);
	//void phase2_auction(vector<GameCard*> &ppMarket, vector<Player*> &players);
	void phase1_determinePlayerOrder();
	void phase2_auction();
	void phase3_buyingResources();
	void phase4_building();
	void phase5_bureaucracy();



private:
	//private attributes
//	GraphBuilder graph;
	vector<GameCard*> deck;
	vector<GameCard*> powerPlantMarket;
	bool step1 = true;
	bool step2 = false;
	bool step3 = false;
	vector<Player*> players;
	Market ppMarket = Market(players);

	//methods needed for phase 2: auction
	string Auction(PowerPlant * &powerplant, vector<Player*> &players, Player * pl);
	vector<GameCard*> EnterAuctioningPhase(vector<GameCard*> &ppMarket, vector<Player*> &players);
	GameCard* drawCard(vector<GameCard*> &deck);
	void Pass(Player * pl);
	bool isNumber(string s);
	int round=1;

	//game setup methods needed
	void makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket);
	void shuffle(vector<GameCard*> &_deck);
//	GameCard* drawCard(vector<GameCard*> &deck);
	void print(vector<GameCard*> &_deck);
	void deleteDeck(vector<GameCard*> &_deck);
	void sortMarket(vector<GameCard*> &_powerPlantMarket);
	

	






};