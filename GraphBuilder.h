/*
	Graph implementation code using adjencyList
*/
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

//classes to build the graph
public:
	GraphBuilder(int totalVertices);
	int getTotalVertices();
	void setTotalVertices(int totalVertices);
	AdjListNode * newAdjListNode(int data, int cost);
	Graph * createGraph(int v);
	void addEdge(Graph * graph, int src, int dest, int cost);
	void printGraph();
	void buildMap();

//variables needed for the graph building
private:
	int totalVertices;
	Graph * graph;

};

#endif
