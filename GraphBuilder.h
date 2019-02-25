/*
	Graph implementation code using adjencyList
*/

#include "City.h";

#ifndef GRAPHBUILDER_HPP_
#define GRAPHBUILDER_HPP_

class GraphBuilder {
//nested classes needed to make the adjency list
public: 
	struct AdjListNode {
		int data;
		//City city;
		int cost;
		AdjListNode * next;
	};

	struct AdjList {
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
	GraphBuilder(int totalVertices);
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	AdjListNode * newAdjListNode(int data, int cost);
	Graph * createGraph(int v);
	void addEdge(Graph * graph, int src, int dest, int cost);
	void printGraph();
	void buildMap();

	//searching algorithm funtions
	MinHeapNode * newMinHeapNode(int v, int dist);
	MinHeap * createMinHeap(int capacity);
	void swapMinHeapNode(struct MinHeapNode ** a, struct MinHeapNode ** b);
	void minHeapify(struct MinHeap * minHeap, int idx);
	int isEmpty(struct MinHeap * minHeap);
	MinHeapNode* extractMin(struct MinHeap* minHeap);
	void decreaseKey(struct MinHeap * minHeap, int v, int dist);
	bool isInMinHeap(struct MinHeap * minHeap, int v);
	void printArr(int dist[], int n);
	void dijkstra(Graph * graph, int vector);

	void SearchCity(int v);
	std::string IsCityAdjacentToOtherCity(int v1, int v2);

//variables needed for the graph building
private:
	int totalVertices;
	Graph * graph;

};

#endif
