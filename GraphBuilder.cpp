
#include<iostream>
#include<cstdlib>
#include "GraphBuilder.h"
using namespace std;


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
GraphBuilder::AdjListNode * GraphBuilder::newAdjListNode(int data, int cost) {

	GraphBuilder::AdjListNode * nptr = new GraphBuilder::AdjListNode;

	nptr->data = data;
	nptr->cost = cost;
	nptr->next = NULL;
	return nptr;

	//we don't need this pointer after it is done making its data
	delete nptr;
	nptr = NULL;
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

void GraphBuilder::addEdge(Graph * graph, int src, int dest, int cost) {

	//Add an edge from src to dest. A new node added to the adjacency list of src
	//node added at beginning
	AdjListNode * nptr = newAdjListNode(dest, cost);

	nptr->next = graph->arr[src].head;
	graph->arr[src].head = nptr;

	//connect from dest to src (since undirected)
	nptr = newAdjListNode(src, cost);
	nptr->next = graph->arr[dest].head;

	graph->arr[dest].head = nptr;


}

void GraphBuilder::printGraph() {

	//loop over each adjacent list
	for (int i = 0; i<graph->v; i++) {
		AdjListNode * root = graph->arr[i].head;
		cout << "Adjacency list of vertex " << i << endl;

		//loop over each node in list
		while (root != NULL) {
			cout << i << " to " << root->data << " costs: " << root->cost << " -> ";
			root = root->next;
		}

		cout << endl;

		//delete every root pointer created
		delete root;
		root = NULL;
	}
}

void GraphBuilder::buildMap() {

	//connect edges
	addEdge(graph, 0, 1, 4);
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 6, 4);
	addEdge(graph, 2, 3, 11);
	addEdge(graph, 2, 4, 11);
	addEdge(graph, 2, 13, 17);
	addEdge(graph, 2, 8, 8);
	addEdge(graph, 2, 6, 6);
	addEdge(graph, 3, 4, 8);
	addEdge(graph, 4, 5, 11);
	addEdge(graph, 4, 14, 11);
	addEdge(graph, 4, 13, 10);
	addEdge(graph, 5, 14, 14);
	addEdge(graph, 6, 8, 6);
	addEdge(graph, 8, 13, 19);
	addEdge(graph, 8, 12, 16);
	addEdge(graph, 8, 11, 18);
	addEdge(graph, 8, 10, 19);
	addEdge(graph, 8, 9, 6);
	addEdge(graph, 9, 10, 19);
	addEdge(graph, 10, 11, 15);
	addEdge(graph, 10, 41, 6);
	addEdge(graph, 10, 30, 17);
	addEdge(graph, 11, 30, 11);
	addEdge(graph, 11, 12, 15);
	addEdge(graph, 12, 13, 16);
	addEdge(graph, 12, 19, 15);
	addEdge(graph, 12, 29, 19);
	addEdge(graph, 13, 14, 7);
	addEdge(graph, 13, 19, 20);
	addEdge(graph, 14, 16, 6);
	addEdge(graph, 14, 15, 2);
	addEdge(graph, 15, 16, 4);
	addEdge(graph, 15, 21, 10);
	addEdge(graph, 15, 24, 20);
	addEdge(graph, 15, 19, 18);
	addEdge(graph, 16, 17, 0);
	addEdge(graph, 16, 18, 2);
	//addEdge(graph, 17, 19, 15);
	addEdge(graph, 18, 20, 9);
	addEdge(graph, 18, 21, 4);
	addEdge(graph, 19, 24, 13);
	addEdge(graph, 19, 27, 8);
	addEdge(graph, 19, 29, 15);
	addEdge(graph, 20, 21, 7);
	addEdge(graph, 20, 22, 19);
	addEdge(graph, 21, 22, 20);
	addEdge(graph, 21, 23, 21);
	addEdge(graph, 22, 23, 18);
	addEdge(graph, 22, 25, 11);
	addEdge(graph, 23, 25, 10);
	addEdge(graph, 23, 26, 11);
	addEdge(graph, 23, 14, 0);
	addEdge(graph, 24, 27, 8);
	addEdge(graph, 24, 28, 13);
	addEdge(graph, 25, 26, 11);
	addEdge(graph, 25, 38, 17);
	addEdge(graph, 26, 38, 6);
	addEdge(graph, 26, 28, 10);
	addEdge(graph, 27, 28, 11);
	addEdge(graph, 27, 29, 15);
	addEdge(graph, 28, 33, 8);
	addEdge(graph, 28, 37, 19);
	addEdge(graph, 28, 38, 12);
	addEdge(graph, 29, 30, 6);
	addEdge(graph, 29, 32, 19);
	addEdge(graph, 29, 33, 21);
	addEdge(graph, 30, 31, 0);
	addEdge(graph, 31, 41, 21);
	addEdge(graph, 31, 32, 13);
	addEdge(graph, 32, 41, 16);
	addEdge(graph, 33, 34, 12);
	addEdge(graph, 33, 37, 18);
	addEdge(graph, 34, 37, 13);
	addEdge(graph, 34, 36, 10);
	addEdge(graph, 34, 35, 12);
	addEdge(graph, 35, 36, 14);
	addEdge(graph, 36, 37, 6);
	addEdge(graph, 37, 38, 15);
	addEdge(graph, 37, 40, 17);
	addEdge(graph, 38, 40, 16);
	addEdge(graph, 38, 39, 16);
	addEdge(graph, 39, 40, 14);


	
	/* // careful not to add any dupilcate edges that we already defined
	addEdge(graph,3,2);
	addEdge(graph,0,4);
	addEdge(graph,1,2);
	addEdge(graph,1,3);
	addEdge(graph,1,4);
	addEdge(graph,2,3);
	addEdge*/
}


