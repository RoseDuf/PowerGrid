//  main.cpp
//  player
//  Driver class for Player object
//change..

#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"
#include <algorithm>

using namespace std;

int main() {
    
    std::cout << "true = " << true << std::endl; // just to emphasize that true = 1
    
    // Select a map
    std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
    std::cout << "1) Germany map" << std::endl;
    std::cout << "2) USA map" << std::endl;
    
    int mapChoice;
    
    std::cin >> mapChoice;
    
    std::string mapFilename;
    if(mapChoice == 1) {
        mapFilename = "germany.map";
    }
    else if(mapChoice == 2) {
        mapFilename = "usa.map"; // TODO
    }
    /*else {
        throw no map exception or something like that
    }//*/
    
    MapData mapData = PowerGridIO::getMapData(mapFilename);
    std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
    vector<string> chosenRegCols;
    
    // Select the number of players in the game
    std::cout << "How many players? (2-6):";
    int amountOfPlayers = 0;
    std::cin >> amountOfPlayers;
    for(int i = 0; i < amountOfPlayers; i++) {
        
        std::cout << "Choose region color " << (i+1) << ":";
        std::string currentRegionColorChoice = "";
        std::cin >> currentRegionColorChoice;
        chosenRegCols.push_back(currentRegionColorChoice);
    }
    
    int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
    GraphBuilder graph = GraphBuilder( amountOfVertices, mapFilename );

    std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
    std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
	std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
    std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;
    
    if( graph.hasDuplicateEdge() || graph.hasMissingEdge() ) {
        std::cout << "The graph is invalid." << std::endl;
    }
    
    return 0;
}
