// I'LL UNCOMMENT THIS ALL DURING THE PRESENTATION.
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
     
	 Player * p1 = new Player("Nicole", "Red");
	 cout << p1->getName() << " has " << p1->getRemainingHouses() << " houses left and " << p1->getTotalWallet() << " Elektros."<< endl;
	 cout << endl;

     std::cout << "true = " << true << std::endl; // just to emphasize that true = 1
     
     // Select a map
     std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
     std::cout << "1) Germany map" << std::endl;
     std::cout << "2) USA map" << std::endl;
     std::cout << "3) An invalid map with (a) duplicate edge(s)" << std::endl;
     std::cout << "4) An invalid map with (a) missing edge(s)" << std::endl;
     
     int mapChoice;
     
     std::cin >> mapChoice;
     
     std::string mapFilename;
     if(mapChoice == 1) {
         mapFilename = "germany.map";
     }
     else if(mapChoice == 2) {
         mapFilename = "usa.map"; // TODO
     }
     else if(mapChoice == 3) {
         mapFilename = "duplicate_edge(s).map";
     }
     else if(mapChoice == 4) {
         mapFilename = "missing_edge(s).map";
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
     
     int amountOfRegionsToChoose = 0;
     if(amountOfPlayers == 2) {
         amountOfRegionsToChoose = 3;
     }
     else if(amountOfPlayers == 3) {
         amountOfRegionsToChoose = 3;
     }
     else if(amountOfPlayers == 4) {
        amountOfRegionsToChoose = 4;
     }
     else if(amountOfPlayers == 5) {
        amountOfRegionsToChoose = 5; 
     }
     else if(amountOfPlayers == 6) {
        amountOfRegionsToChoose = 5; 
     }
     
     for(int i = 0; i < amountOfRegionsToChoose; i++) {
         
         std::cout << "Choose region color " << (i+1) << ":";
         std::string currentRegionColorChoice = "";
         std::cin >> currentRegionColorChoice;
         chosenRegCols.push_back(currentRegionColorChoice);
     }
     
     int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
     GraphBuilder graph = GraphBuilder( amountOfVertices, mapFilename );
 
     std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
     std::cout << std::endl;
     std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
     std::cout << std::endl;
 	std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
     std::cout << std::endl;
     std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;
     
     std::cout << std::endl;
     
     if( graph.hasDuplicateEdge() || graph.hasMissingEdge() ) {
         std::cout << "The map is invalid." << std::endl;
     }
     else {
         std::cout << "The map is valid." << std::endl;
     }

	 cout << endl;
	 cout << "After buying a city..." << endl;
	 graph.add_CityToPlayer_and_PlayerToMap(p1, "Berlin");
	 cout << p1->getName() << " has " << p1->getRemainingHouses() << " houses left." << endl;

	 delete p1;
	 p1 = NULL;
     
     return 0;
 }
