//  main.cpp
//  player
//  Driver class for Player object
//

#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;

int main() {
    
    /*
    GameState gameState = GameStateIO::readXmlFile("/home/deniz/kdevelop_projects/PowerGrid/powergrid_cities.map");
    std::vector<City> cities = gameState.getCities();
    std::vector<EdgeTriplet> edgeTriplets = gameState.getEdgeTriplets();
    std::cout << "hilo" << std::endl;
     */
    
    
}


/*//  main.cpp
//  player
//  Driver class for Player object
//

#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"


using namespace std;

int main() {

	ElektroBill elektro = ElektroBill(10, 5);
	RessourceToken resource = RessourceToken(3, "oil");
	PowerPlant powerplant = PowerPlant(3, 2, 2, "oil", "");
	Player p1 = Player("Nicole", "Red");
	p1.collectElektro(elektro);

	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "/home/deniz/kdevelop_projects/PowerGrid/powergrid_cities.map");
	graph.buildMap();

	graph.printGraph();

	//Test Cases
	graph.test_SizeOfMap_and_FileMap();
	graph.test_Duplicate_Edges();
	graph.test_MissingEdges();

	//add tokens to map
	graph.add_ElektrosToCity(elektro, "Berlin");
	graph.add_ResourcesToCity(resource, "Berlin");
	graph.add_PowerPlantToCity(powerplant, "Berlin");

	//print contents 
	graph.SearchCity("Berlin");

	//add player to city
	graph.AddPlayerToCity(p1, "Berlin");

	//print contents
	graph.SearchCity("Berlin");

	//print cities owned by player
	p1.toString();

	cin.get();
}
*/
