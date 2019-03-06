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

	struct AdjList {
		City city;
		Player player;
		AdjListNode * head;
	};

	struct Graph {
		int v;
		AdjList * arr;
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
	GraphBuilder(int totalVertices, std::string file);
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	AdjListNode * newAdjListNode(int cityno, string cityname, string citycolor, int cost);
	Graph * createGraph(int v);
	void addEdge(Graph * graph, EdgeTriplet edges);
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
	void AddPlayerToCity(Player player, City city);
	vector<City> FindCitiesOwnedByPlayer(Player player);
	bool IsCityAdjacentToOtherCity(int v1, int v2);
	void SearchCity(string cityName);
	int CostFromOneCityToAnother(int v1, int v2);
	void buildMap();

//variables needed for the graph building
private:
	int totalVertices;
	Graph * graph;
	std::string file;
	GameState gameState;
	std::vector<EdgeTriplet> edges;
	//std::vector<CityTriplet> cities;

};

#endif
