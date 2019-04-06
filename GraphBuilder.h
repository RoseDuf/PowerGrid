/*
Graph implementation code using adjencyList
*/

#ifndef GRAPHBUILDER_HPP_
#define GRAPHBUILDER_HPP_

#include "City.h"
#include "Player.hpp"
#include "GameState.hpp"
#include "PowerGridIO.hpp"

class GraphBuilder {
	//nested classes needed to make the adjency list
public:
	struct AdjListNode {
		City city;
		int cost;
		AdjListNode * next;
		~AdjListNode() {
			delete next;
			next = NULL;
		}
	};

	struct CityList {
		City city;
		vector<Player> player;
		vector<PowerPlant> powerplants;
		//vector<ResourceToken> resources;
		vector<Elektro> elektros;
		AdjListNode * head;
		~CityList() {
			delete head;
			head = NULL;
		}
	};

	struct Graph {
		int v;
		vector<CityList> arr;
		~Graph() {}
	};

	/*
	// Structure to represent a min heap node
	struct MinHeapNode
	{
	int v;
	int dist;
	};
	// Structure to represent a min heap
	struct MinHeap
	{
	int size;      // Number of heap nodes present currently
	int capacity;  // Capacity of min heap
	int *pos;     // This is needed for decreaseKey()
	MinHeapNode ** array;
	};
	*/

	//classes to build the graph
public:
	//building class functions
	//GraphBuilder(int totalVertices);
	GraphBuilder(int totalVertices, std::string file);
	~GraphBuilder();
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	vector<vector<int>> getConnected();
	AdjListNode * newAdjListNode(int cityno, string cityname, string citycolor, int cost);
	Graph * createGraph(int v, vector<City> cities);
	void addEdge(Graph * graph, EdgeTriplet edges);
	void addConnectedCitiestoVector();
	void printGraph();
	void printAvailableCities();

	bool areChosenRegionsConnected(vector<string> chosenRegCols);

	//searching algorithm funtions
	/*
	MinHeapNode * newMinHeapNode(int v, int dist);
	MinHeap * createMinHeap(int capacity);
	void swapMinHeapNode(struct MinHeapNode ** a, struct MinHeapNode ** b);
	void minHeapify(struct MinHeap * minHeap, int idx);
	int isEmpty(struct MinHeap * minHeap);
	MinHeapNode * extractMin(struct MinHeap* minHeap);
	void decreaseKey(struct MinHeap * minHeap, int v, int dist);
	bool isInMinHeap(struct MinHeap * minHeap, int v);
	void printArr(int dist[], int n);
	int findVertex(int dist[], int n);
	void dijkstra(Graph * graph, int vector);
	*/

	//additional functions
	City findCityByName(string name);
	void removeRegions(string color);
	bool add_CityToPlayer_and_PlayerToMap(Player * pl, string name);
	void AddPlayerToMap(Player * pl);
	int HowManyPlayersAreInCity(string cityName);
	vector<City> FindCitiesOwnedByPlayer(Player * player);
	bool IsCityAdjacentToOtherCity(string city1, string city2);
	void SearchCity(string cityName);
	//void add_ElektrosToCity(Elektro el, string name);
	//void add_ResourcesToCity(ResourceToken rt, string name);
	//void add_PowerPlantToCity(PowerPlant pp, string city);
	int CostFromOneCityToAnother(string city1, string city2);
	bool test_SizeOfMap_and_FileMap();
	bool hasDuplicateEdge();
	bool hasMissingEdge();
	void buildMap();

	bool eachRegionHasSevenCities();
    bool isValidGraph();
	//variables needed for the graph building
private:
	int totalVertices;
	Graph * graph;
	std::string file;
	MapData mapData;
	std::vector<EdgeTriplet> edges;
	//std::vector<City> cities; // I don't think this is needed; it's provided by std::get<0>(mapData) anyways (and mapData is a field in GraphBuilder).
	vector<vector<int>> connected;
	vector<AdjacentRegionsTriplet> getChosenAdjacentRegionsTriplets(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols);
	bool hasPath(string begCol, string endCol, vector<AdjacentRegionsTriplet> arts, int pathSize, const int MAX_PATH_SIZE);
	bool areChosenRegionsConnected(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols, const int MAX_PATH_SIZE);
	void populateAllRegionColors();
	std::vector<std::string> ALL_REGION_COLORS;
};

#endif
