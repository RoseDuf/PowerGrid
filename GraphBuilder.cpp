
#include<iostream>
#include<cstdlib>
#include "GraphBuilder.h"
using namespace std;

GraphBuilder::GraphBuilder() {
	int totalVertices = 0;
	Graph * graph = createGraph(totalVertices);
}

GraphBuilder::GraphBuilder(int tv) {
	totalVertices = tv;
	graph = createGraph(totalVertices);
}

int GraphBuilder::getTotalVertices() {
	return totalVertices;
}

void GraphBuilder::setTotalVertices(int tv) {
	totalVertices = tv;
}

//create a new node
GraphBuilder::AdjListNode * GraphBuilder::newAdjListNode(int data) {
	GraphBuilder::AdjListNode * nptr = new GraphBuilder::AdjListNode;
	nptr->data = data;
	nptr->next = NULL;
	return nptr;
}

//function to create a graph of v vertices
GraphBuilder::Graph * GraphBuilder::createGraph(int totalVertices) {
	GraphBuilder::Graph * graph = new GraphBuilder::Graph;
	graph->v = totalVertices;
	//create an array of adjacency list. size of array - V
	graph->arr = new GraphBuilder::AdjList[totalVertices];
	//initialize with NULL (e.g root=NULL)
	for (int i = 0; i<totalVertices; i++) {
		graph->arr[i].head = NULL;
	}
	return graph;
}

void GraphBuilder::addEdge(Graph * graph, int src, int dest) {
	//Add an edge from src to dest. A new node added to the adjacency list of src
	//node added at beginning
	AdjListNode * nptr = newAdjListNode(dest);
	nptr->next = graph->arr[src].head;
	graph->arr[src].head = nptr;
	//connect from dest to src (since undirected)
	nptr = newAdjListNode(src);
	nptr->next = graph->arr[dest].head;
	graph->arr[dest].head = nptr;
}

void GraphBuilder::printGraph() {
	//loop over each adjacent list
	for (int i = 0; i<graph->v; i++) {
		AdjListNode *root = graph->arr[i].head;
		cout << "Adjacency list of vertex " << i << endl;
		//loop over each node in list
		while (root != NULL) {
			cout << root->data << " -> ";
			root = root->next;
		}
		cout << endl;
	}
}

void GraphBuilder::buildMap() {

	//connect edges
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	/*
	addEdge(graph,0,1);
	addEdge(graph,0,4);
	addEdge(graph,1,2);
	addEdge(graph,1,3);
	addEdge(graph,1,4);
	addEdge(graph,2,3);
	addEdge(graph,3,4);
	*/
}

std::string GraphBuilder::getSerializedData(void) {
    // TODO
    return "";
}
void GraphBuilder::setSerializedData(std::string serializedData) {
    // TODO
}
