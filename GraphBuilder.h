/*
	Graph implementation code using adjencyList
*/

#include "City.h"
#include "player.hpp"
#include "GameState.hpp"
#include "GameStateIO.hpp"

#ifndef GRAPHBUILDER_HPP_
#define GRAPHBUILDER_HPP_

class GraphBuilder {
//nested classes needed to make the adjency list
public: 
	struct AdjListNode {
		City city;
		
		Player player;
		int cost;
		AdjListNode * next;
	};

	struct CityList {
		City city;
		Player player;
		vector<PowerPlant> powerplants;
		vector<RessourceToken> resources;
		Elektro elektros;
		AdjListNode * head;
	};

	struct Graph {
		int v;
		CityList * arr;
	};

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

//classes to build the graph
public:
	//building class functions
	GraphBuilder(int totalVertices);
	GraphBuilder(int totalVertices, std::string file);
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	AdjListNode * newAdjListNode(int cityno, string cityname, string citycolor, int cost);
	Graph * createGraph(int v, vector<City> cities);
	void addEdge(Graph * graph, EdgeTriplet edges);
	void addConnectedCitiestoVector();
	void printGraph();

	//searching algorithm funtions
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

	//additional functions
	//City findCityByName(string name);
	void AddPlayerToCity(Player player, string name);
	vector<City> FindCitiesOwnedByPlayer(Player player);
	bool IsCityAdjacentToOtherCity(int v1, int v2);
	void SearchCity(string cityName);
	void add_ElektrosToCity(Elektro el, string name);
	void add_ResourcesToCity(RessourceToken rt, string name);
	void add_PowerPlantToCity(PowerPlant pp, string city);
	int CostFromOneCityToAnother(int v1, int v2);
	bool test_SizeOfMap_and_FileMap();
	bool test_Duplicate_Edges();
	bool test_MissingEdges();
	void buildMap();


//variables needed for the graph building
private:
	int totalVertices;
	Graph * graph;
	std::string file;
	GameState gameState = GameStateIO::readXmlFile(file);
	std::vector<EdgeTriplet> edges;
	std::vector<City> cities;
	vector<vector<int>> connected;

};

#endif
