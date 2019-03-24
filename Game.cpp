//Game Play Driver for Phase 3 + 4
//GameState getTurnOfPlayer returns int

#include "GameState.hpp"
#include "Game.h"
using namespace std;

Game::Game() {

}



void Game::reversePlayerOrder() {

	int playerTurn = 0;
	playerTurn = GameState.getTurnOfPlayer(); 


}

//players buy resources for their powerplants from resource market
//phase is played in reverse player order

//In reverse turn order, players can buy resources for their plants. 
//Players may only purchases resources they can use, and each plant 
//may only hold twice the number of resources it needs to run.
//Thus a plant that uses two oil may hold up to four oil. As resources 
//are purchased, they become more expensive, thus the person who is 
//last in turn order can buy resources at the cheapest prices
//for that round.

void Game::BuyingResources() {


}

//Players start or add cities to their networks
//Show possessions of each player at end of Phase 4

//In reverse turn order, players may build into cities. In the first round, 
//a player may choose to build into any city that is not already occupied.
//A player may continue to expand by paying the cost to
//build into the desired city slot plus the value of all connections to that 
//city from an already occupied city.No player may build into more than one 
//slot in a city.Slot one costs 10'Elektros' and is the
//only slot available during Step 1. During Step 2, the second slot is 
//available at a cost of 15 Electros, and in Step 3, the final slot is 
//available at a cost of 20 Electros.

void Game::BuildingCities() {

}

