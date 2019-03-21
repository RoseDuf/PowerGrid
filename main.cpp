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
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "ResourceToken.hpp"

using namespace std;

int main() {
//
	Elektro elektro = Elektro(10, 5, 50);
	ResourceToken resource = ResourceToken(3, "oil");
	PowerPlant powerplant = PowerPlant(3, 2, 2, "oil", "");
	Player p1 = Player("Nicole", "Red");
	//p1.collectElektro(elektro);

	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "powergrid_cities.map");
	graph.buildMap();

	graph.printGraph();

	cout << endl;

	//prints the contents of the 2D vector "connected" from GraphBuilder.h
	/*vector<vector<int>> vec = graph.getConnected();
  
	for (int i = 0; i < vec.size(); i++) {
		cout << "for slot " << i << " there is: " << endl;
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << endl;
		}
	}*/

	//bool check1, check2, check3;
	//Test Cases
	graph.CostFromOneCityToAnother(0, 1);
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

	//print contents
	graph.SearchCity("Berlin");

	cout << endl;

	//print cities owned by player
	p1.toString();

	cin.get();
}

