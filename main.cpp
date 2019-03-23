//  main.cpp
//  player
//  Driver class for Player object
//
/*
#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;


int main() {
    GameState gameState = GameStateIO::readXmlFile("powergrid_cities.map");
    std::vector<City> cities = gameState.getCities();
    std::vector<EdgeTriplet> edgeTriplets = gameState.getEdgeTriplets();
    std::cout << "hilo" << std::endl;

	for (int i = 0; i < cities.size(); i++) {
		std::cout << cities[i].getCityNumber() << endl;
	}

	
	for (int i = 0; i < edgeTriplets.size(); i++) {
		std::cout << std::get<0>(edgeTriplets[i]).getCityNumber() << endl;
	}

	

}
*/

//  main.cpp
//  player
//  Driver class for Player object
//

#include <iostream>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "ResourceToken.hpp"

using namespace std;

static void DeterminePlayerOrder(vector<Player*> players, int round) {

	vector<int> playerOrder;

	if (round == 1) {
		for (int i = 0; i < players.size(); i++) {
			playerOrder.push_back(i + 1);
		}

		//give random turn to each player
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(playerOrder.begin(), playerOrder.end(), g);

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(playerOrder[i]);
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}

		//sort players by the number of cities they have (for the rest of the game)
		std::sort(players.begin(), players.end(), Player::compById);

		round += 1;
	}

	for (int i = 0; i < players.size(); i++) {
		players.at(i)->setplayerOrder(players.size() - i);
	}

	for (int i = 0; i < players.size(); i++) {
		cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
	}
}

int main() {

//============================== Assignment 1 ================================================
	/*
	Elektro elektro = Elektro(10, 5, 50);
	ResourceToken resource = ResourceToken(3, "oil");
	PowerPlant powerplant = PowerPlant(3, 2, 2, "oil", "");

	Player * p1 = new Player("Nicole", "Red");
	//p1.collectElektro(elektro);
	*/
	
	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "powergrid_cities.map");
	graph.buildMap();

	/*
	graph.printGraph();

	cout << endl;

	//prints the contents of the 2D vector "connected" from GraphBuilder.h
	//vector<vector<int>> vec = graph.getConnected();
  
	//for (int i = 0; i < vec.size(); i++) {
	//	cout << "for slot " << i << " there is: " << endl;
	//	for (int j = 0; j < vec[i].size(); j++) {
	//		cout << vec[i][j] << endl;
	//	}
	//}

	//bool check1, check2, check3;
	//Test Cases
	//graph.CostFromOneCityToAnother(0, 1);
	//std::cout << std::boolalpha;
	graph.test_SizeOfMap_and_FileMap();
	//cout << check3 << endl;
	graph.test_Duplicate_Edges();
	//cout << check1 << endl;
	graph.test_MissingEdges();
	//cout << check2 << endl;

	cout << endl;

	//add tokens to map
	graph.add_ElektrosToCity(elektro, "Berlin");
	graph.add_ResourcesToCity(resource, "Berlin");
	graph.add_PowerPlantToCity(powerplant, "Berlin");

	cout << endl;
	//print contents 
	graph.SearchCity("Berlin");

	cout << endl;

	//add player to city
	graph.AddPlayerToCity(p1, "Berlin");
	
	vector<City> citiesOwned = graph.FindCitiesOwnedByPlayer(p1);

	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << "Player: " << p1->getName() << ", Color: " << p1->getColor()
			<< ", is in City: " << citiesOwned[i].getCityName() << endl;
	}

	cout << endl;

	//print contents
	graph.SearchCity("Berlin");

	cout << endl;

	//print cities owned by player
	p1->toString();

	cin.get();
	*/

	//============================== Assignment 2, task 2, ================================================
	
	
	//vector of Players
	vector<Player*> players;
	players.push_back(new Player("Nicole", "Red"));
	players.push_back(new Player("Voldermort", "Green"));
	players.push_back(new Player("Pikachu", "Blue"));
	players.push_back(new Player("Smith", "Purple"));

	graph.AddPlayerToCity(players[0], "Berlin");
	graph.AddPlayerToCity(players[0], "Frankfurt-O");
	graph.AddPlayerToCity(players[1], "Kiel");
	graph.AddPlayerToCity(players[2], "Frankfurt-M");
	graph.AddPlayerToCity(players[2], "Hamburg");
	graph.AddPlayerToCity(players[2], "Cuxhaven");


	//Game loop !!!!

	int numPlayers = players.size();
	vector<int> playerOrder;

	bool gameIsNotFinished = false;
	int round = 1;

	while (gameIsNotFinished == false){
		
		while (round >= 1) {
			
			//task 2 - step 1
			DeterminePlayerOrder(players, round);
			
			//task2 - step 2
			//to be completed

			round = 0;
		}
		gameIsNotFinished = true;
	}

	return 0;
}

