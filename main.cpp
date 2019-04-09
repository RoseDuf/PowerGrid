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
#include <ctype.h>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "Market.hpp"
#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;


int main() {

//============================== Assignment 1 ================================================
	
	Elektro elektro = Elektro(10, 5, 50);
	//ResourceToken resource = ResourceToken(3, "oil");
	PowerPlant powerplant = PowerPlant(3, 2, 2, 0, 0, 0);

	//p1.collectElektro(elektro);
	
	
	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "germany.map");
	graph.buildMap();

	
	Player * p1 = new Player("Nicole", "Red");
	Player * p2 = new Player("Rose", "Green");
	graph.printGraph();
	

	cout << endl;

	graph.removeRegions("ORANGE");

	graph.printGraph();
	graph.printAvailableCities();

	graph.IsCityAdjacentToOtherCity("Berlin", "Konstanz");

	graph.CostFromOneCityToAnother("Flensburg", "Kiel");
	cout << endl;
	
	//prints the contents of the 2D vector "connected" from GraphBuilder.h
	vector<vector<int>> vec = graph.getConnected();
  
	for (int i = 0; i < vec.size(); i++) {
		cout << "for slot " << i << " there is: " << endl;
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << endl;
		}
	}

	bool check1, check2, check3;
	//Test Cases
	//graph.CostFromOneCityToAnother(0, 1);
	std::cout << std::boolalpha;
	graph.test_SizeOfMap_and_FileMap();
	//cout << check3 << endl;
	graph.hasDuplicateEdge();
	//cout << check1 << endl;
	check2 = graph.hasMissingEdge();
	cout << check2 << endl;

	cout << endl;

	//add tokens to map
	//graph.add_ElektrosToCity(elektro, "Berlin");
	//graph.add_ResourcesToCity(resource, "Berlin");
	//graph.add_PowerPlantToCity(powerplant, "Berlin");

	cout << endl;
	//print contents 
	graph.SearchCity("Berlin");

	cout << endl;

	
	//add player to city
	City c1 = City(1, "Kiel", "GREEN");
	City c2 = City(2, "Hamburg", "GREEN");
	check3 = graph.add_CityToPlayer_and_PlayerToMap(p1, "Berlin");
	cout << check3 << endl;
	//p1->addCity(c1);
	//p1->addCity(c2);
	check3 = graph.add_CityToPlayer_and_PlayerToMap(p2, "Hamburg");
	cout << check3 << endl;
	graph.AddPlayerToMap(p1);
	
	vector<City> citiesOwned = graph.FindCitiesOwnedByPlayer(p1);

	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << "Player: " << p1->getName() << ", Color: " << p1->getColor()
			<< ", is in City: " << citiesOwned[i].getCityName() << endl;
	}

	cout << endl;

	//print contents
	graph.SearchCity("Berlin");
	graph.SearchCity("Kiel");
	graph.SearchCity("Hamburg");
	graph.HowManyPlayersAreInCity("Berlin");
	graph.HowManyPlayersAreInCity("Hamburg");

	cout << endl;

	//print cities owned by player
	p1->toString();

	cin.get();
	
	return 0;
}
