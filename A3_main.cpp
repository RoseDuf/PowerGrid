
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Game.h"


using namespace std;
//using namespace HelperFunctions;


int main()
{
	/*
	int amountOfRegionsToChoose = 0;
	bool AI = false;
	// Select a map
	std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
	std::cout << "1) Germany map" << std::endl;
	std::cout << "2) USA map" << std::endl;
	std::cout << "3) An invalid map with (a) duplicate edge(s)" << std::endl;
	std::cout << "4) An invalid map with (a) missing edge(s)" << std::endl;

	int mapChoice;

	std::cin >> mapChoice;

	std::string mapFilename;
	if (mapChoice == 1) {
		mapFilename = "germany.map";
	}
	else if (mapChoice == 2) {
		mapFilename = "usa.map"; // TODO
	}
	else if (mapChoice == 3) {
		mapFilename = "duplicate_edge(s).map";
	}
	else if (mapChoice == 4) {
		mapFilename = "missing_edge(s).map";
	}


	MapData mapData = PowerGridIO::getMapData(mapFilename);
	std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
	vector<string> chosenRegCols;

	if (AI == true) {
		//powerGridAI.executeRegionColorChoice(std::vector<std::string> alreadyChosenColors) or something like that
	}
	else {
		for (int i = 0; i < amountOfRegionsToChoose; i++) {

			std::cout << "Choose region color " << (i + 1) << ":";
			std::string currentRegionColorChoice = "";
			std::cin >> currentRegionColorChoice;
			chosenRegCols.push_back(currentRegionColorChoice);
		}
	}
	int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
	GraphBuilder graph = GraphBuilder(amountOfVertices, mapFilename);
	//graph = GraphBuilder(amountOfVertices, mapFilename);

	std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
	std::cout << std::endl;
	std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;

	std::cout << std::endl;

	while (graph.hasDuplicateEdge() || graph.hasMissingEdge()) {
		std::cout << "ERROR: The map is invalid." << std::endl;
		cout << endl;
		std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
		std::cout << "1) Germany map" << std::endl;
		std::cout << "2) USA map" << std::endl;
		std::cout << "3) An invalid map with (a) duplicate edge(s)" << std::endl;
		std::cout << "4) An invalid map with (a) missing edge(s)" << std::endl;

		int mapChoice;

		std::cin >> mapChoice;

		std::string mapFilename;
		if (mapChoice == 1) {
			mapFilename = "germany.map";
		}
		else if (mapChoice == 2) {
			mapFilename = "usa.map"; // TODO
		}
		else if (mapChoice == 3) {
			mapFilename = "duplicate_edge(s).map";
		}
		else if (mapChoice == 4) {
			mapFilename = "missing_edge(s).map";
		}
		//else {
		// throw no map exception or something like that
		//}

		MapData mapData = PowerGridIO::getMapData(mapFilename);
		std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
		vector<string> chosenRegCols;

		for (int i = 0; i < amountOfRegionsToChoose; i++) {

			std::cout << "Choose region color " << (i + 1) << ":";
			std::string currentRegionColorChoice = "";
			std::cin >> currentRegionColorChoice;
			chosenRegCols.push_back(currentRegionColorChoice);
		}

		int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
		graph = GraphBuilder(amountOfVertices, mapFilename);

		std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
		std::cout << std::endl;
		std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;

		std::cout << std::endl;
	}

	std::cout << "The map is valid." << std::endl;

	*/
	Game test;
	test.deckSetup();
	test.setUpPlayers();
	test.setUpMap();
	test.phase1_determinePlayerOrder();
	test.phase2_auction();
	test.phase3_buyingResources();
	test.phase4_building();
	test.phase5_bureaucracy();
	return 0;
}

