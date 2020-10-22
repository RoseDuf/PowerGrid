//(Rose)
//Graph implementation code using adjencyList


#ifndef GRAPHBUILDER_HPP_
#define GRAPHBUILDER_HPP_

#include "City.h"
#include "Player.hpp"
#include "GameState.hpp"
#include "PowerGridIO.hpp"

class GraphBuilder {
	//nested classes needed to make the adjency list
public:
	//Each node is a city with a cost
	struct AdjListNode {
		City city;
		int cost;
		AdjListNode * next;
		~AdjListNode() {
			delete next;
			next = NULL;
		}
	};

	//Each city is owned by a player, is powered by a powerplant and has a cost (elektros)
	struct CityList {
		City city;
		vector<Player> players;
		vector<PowerPlant> powerplants;
		vector<Elektro> elektros;
		AdjListNode * head;
		~CityList() {
			delete head;
			head = NULL;
		}
	};

	struct Graph {
		int v; //total vertices
		vector<CityList> arr;
		~Graph() {}
	};

public:
	//classes to build the graph

	//constructors
	GraphBuilder(int totalVertices, std::string file);
	GraphBuilder();
	~GraphBuilder();

	//accessors and mutators
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	vector<vector<int>> getConnected();
	string getMapName();

	AdjListNode * newAdjListNode(int cityno, string cityname, string citycolor, int cost);
	Graph * createGraph(int v, vector<City> cities);
	void addEdge(Graph * graph, EdgeTriplet edges);
	void addConnectedCitiestoVector();
	void printGraph();
	void printAvailableCities();
	bool findCityByNameBool(string name);
	void playerNameInCity(string city3);
	bool areChosenRegionsConnected(vector<string> chosenRegCols);

	//additional functions
	City findCityByName(string name);
	void removeRegions(string color);
	bool add_CityToPlayer_and_PlayerToMap(Player * pl, string name);
	void AddPlayerToMap(Player * pl);
	int HowManyPlayersAreInCity(string cityName);
	vector<Player> PlayersInCIty(string cityName);
	string PrintOwnedCities();
	vector<City> FindCitiesOwnedByPlayer(Player * player);
	bool IsCityAdjacentToOtherCity(string city1, string city2);
	void searchCity(string cityName);
	int CostFromOneCityToAnother(string city1, string city2);
	bool test_SizeOfMap_and_FileMap();
	bool hasDuplicateEdge();
	bool hasMissingEdge();

	bool eachRegionHasSevenCities();
    bool isValidGraph();
    std::vector< std::pair<City,int> > getStillOccupiableCitiesAndOccupationAmounts(int gameStep);
    std::vector<std::string> getAllRegionColors() const;

private:
	//variables needed for the graph building
	void buildMap();
	int totalVertices;
	Graph * graph;
	std::string file;
	MapData mapData;
	std::vector<EdgeTriplet> edges;
	std::vector<City> cities;
	vector<vector<int>> connected;
	AdjListNode* nptr;

	vector<AdjacentRegionsTriplet> getChosenAdjacentRegionsTriplets(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols);
	bool hasPath(string begCol, string endCol, vector<AdjacentRegionsTriplet> arts, int pathSize, const int MAX_PATH_SIZE);
	bool areChosenRegionsConnected(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols, const int MAX_PATH_SIZE);
	void populateAllRegionColors();
	std::vector<std::string> ALL_REGION_COLORS;
};

#endif
