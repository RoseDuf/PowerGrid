
#include<iostream>
#include<cstdlib>
#include <utility>      // std::pair, std::get
#include "GraphBuilder.h"
#include "GameState.hpp"
#include "City.h"
#include "player.hpp"
#include <limits.h>
using namespace std;


GraphBuilder::GraphBuilder(int tv, std::string file) {
	totalVertices = tv;
	graph = createGraph(totalVertices);
	gameState = GameStateIO::readXmlFile(file);
	edges = gameState.getEdgeTriplets();
}

int GraphBuilder::getTotalVertices() {
	return totalVertices;
}

void GraphBuilder::setTotalVertices(int tv) {
	totalVertices = tv;
}

//create a new node
GraphBuilder::AdjListNode * GraphBuilder::newAdjListNode(int cityno, string cityname, string citycolor, int cost) {

	AdjListNode * nptr = new AdjListNode;

	nptr->city = City(cityno, cityname, citycolor);
	nptr->cost = cost;
	nptr->next = NULL;
	return nptr;
}

//function to create a graph of v vertices
GraphBuilder::Graph * GraphBuilder::createGraph(int totalVertices/*, vector<CityTriplet> cities*/) {

	Graph * graph = new Graph;

	graph->v = totalVertices;

	//create an array of adjacency list. size of array - V
	graph->arr = new AdjList[totalVertices];

	//initialize with NULL (e.g root=NULL)
	for (int i = 0; i<totalVertices; i++) {
		//graph->arr[i].city.setCityNumber = cities[i].std::get<0>(cities).getCityNumber();
		//graph->arr[i].city.setCityName = cities[i].std::get<0>(cities).getCityName();
		//graph->arr[i].city.setCityColor = cities[i].std::get<0>(cities).getCityColor();
		//graph->arr[i].player = Player();
		graph->arr[i].head = NULL;
	}
	return graph;
}

void GraphBuilder::addEdge(Graph * graph, EdgeTriplet edges) {

	//Add an edge from src to dest. A new node added to the adjacency list of src
	//node added at beginning
	AdjListNode * nptr = newAdjListNode(std::get<1>(edges).getCityNumber(),
										std::get<1>(edges).getCityName(),
										std::get<1>(edges).getCityColor(),
										std::get<2>(edges));

	nptr->next = graph->arr[std::get<0>(edges).getCityNumber()].head;
	graph->arr[std::get<0>(edges).getCityNumber()].head = nptr;

	//connect from dest to src (since undirected)
	nptr = newAdjListNode(std::get<0>(edges).getCityNumber(),
						  std::get<0>(edges).getCityName(),
						  std::get<0>(edges).getCityColor(),
						  std::get<2>(edges));
	nptr->next = graph->arr[std::get<1>(edges).getCityNumber()].head;

	graph->arr[std::get<1>(edges).getCityNumber()].head = nptr;
}

void GraphBuilder::printGraph() {

	//loop over each adjacent list
	for (int i = 0; i<graph->v; i++) {
		AdjListNode * root = graph->arr[i].head;
		cout << "Adjacency list of vertex " << i << endl;

		//loop over each node in list
		while (root != NULL) {
			cout << i << " to " << root->city.getCityNumber << " costs: " << root->cost << " -> ";
			root = root->next;
		}

		cout << endl;

		//delete every root pointer created
		delete root;
		root = NULL;
	}
}

/* ----------------------------------------------------------------------------------------------------------
	Dijkstra Search algorithm source code taken and modified from: 
	https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
   ----------------------------------------------------------------------------------------------------------
*/
//function to create a new Min Heap Node 
GraphBuilder::MinHeapNode * GraphBuilder::newMinHeapNode(int v, int dist) {
	MinHeapNode * minHeapNode = new MinHeapNode;
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

//function to create a Min Heap 
GraphBuilder::MinHeap * GraphBuilder::createMinHeap(int capacity) {
	MinHeap * minHeap = new MinHeap;
	minHeap->pos = new int[capacity];
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = new MinHeapNode * [capacity];
	return minHeap;
}

//function to swap two nodes of min heap. Needed for min heapify 
void GraphBuilder::swapMinHeapNode(struct MinHeapNode ** a, struct MinHeapNode ** b) {
	struct MinHeapNode * t = * a;
	* a = * b;
	* b = t;
}

//function to heapify at given idx
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void GraphBuilder::minHeapify(struct MinHeap * minHeap, int idx) {
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->array[left]->dist < minHeap->array[smallest]->dist)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->array[right]->dist < minHeap->array[smallest]->dist)
		smallest = right;

	if (smallest != idx) {
		// The nodes to be swapped in min heap 
		MinHeapNode * smallestNode = minHeap->array[smallest];
		MinHeapNode * idxNode = minHeap->array[idx];

		// Swap positions 
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

//function to check if the given minHeap is empty or not 
int GraphBuilder::isEmpty(struct MinHeap * minHeap) {
	return minHeap->size == 0;
}

//function to extract minimum node from heap 
GraphBuilder::MinHeapNode * GraphBuilder::extractMin(struct MinHeap * minHeap) {
	if (isEmpty(minHeap))
		return NULL;

	// Store the root node 
	struct MinHeapNode * root = minHeap->array[0];

	// Replace root node with last node 
	struct MinHeapNode * lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node 
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root 
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

//Function to decreases dist value of a given vertex v. This function 
//uses pos[] of min heap to get the current index of node in min heap 
void GraphBuilder::decreaseKey(MinHeap * minHeap, int v, int dist) {
	// Get the index of v in  heap array 
	int i = minHeap->pos[v];

	// Get the node and update its dist value 
	minHeap->array[i]->dist = dist;

	// Travel up while the complete tree is not hepified. 
	// This is a O(Logn) loop 
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
		// Swap this node with its parent 
		minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		// move to parent index 
		i = (i - 1) / 2;
	}
}

//function to check if a given vertex 'v' is in min heap or not 
bool GraphBuilder::isInMinHeap(MinHeap *minHeap, int v) {
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

//function used to print the solution 
void GraphBuilder::printArr(int dist[], int n) {
	printf("Vertex   Total Cost from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

int GraphBuilder::findVertex(int dist[], int n) {
	for (int i = 0; i < n; ++i) {
		if (dist[i] == 0)
			return i;
	}
}

//function that calulates distances of shortest paths from src to all vertices. It is a O(ELogV) function 
//dijkstra search algorithm
void GraphBuilder::dijkstra(Graph * graph, int src) {
	int V = graph->v; // Get the number of vertices in graph 
	int * dist = new int[V];     // dist values used to pick minimum weight edge in cut 
	
	// minHeap represents set E 
	MinHeap * minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices  
	for (int v = 0; v < V; ++v) {
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first 
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	//minHeap->pos[src] = src; //this is useless
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V 
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes 
	// whose shortest distance is not yet finalized. 
	while (!isEmpty(minHeap)) {
		// Extract the vertex with minimum distance value 
		struct MinHeapNode * minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number 

		// Traverse through all adjacent vertices of u (the extracted 
		// vertex) and update their distance values 
		struct AdjListNode * pCrawl = graph->arr[u].head;
		while (pCrawl != NULL) {
			int v = pCrawl->city.getCityNumber;

			// If shortest distance to v is not finalized yet, and distance to v 
			// through u is less than its previously calculated distance 
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->cost + dist[u] < dist[v]) {
				dist[v] = dist[u] + pCrawl->cost;

				// update distance value in min heap also 
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	// print the calculated shortest distances 
	//printArr(dist, V);

	//find the vertex
	//findVertex(dist, V);

	delete[] dist;
	dist = NULL;
}

// ----------------------------------------------------------------------------------------------------------

void GraphBuilder::AddPlayerToCity(Player player, City city) {
	int arrayNumber = city.getCityNumber;

	for (int i = 0; i < totalVertices; i++) {
		if (i == arrayNumber) {
			graph->arr[i].player = player;
		}
	}
}

vector<City> GraphBuilder::FindCitiesOwnedByPlayer(Player pl) {

	vector<City> citiesOwned;

	for (int i = 0; i < totalVertices; i++) {
		if (graph->arr[i].player.getName == pl.getName) {
			citiesOwned.push_back(graph->arr[i].city);
		}	
	}
	return citiesOwned;
}

bool GraphBuilder::IsCityAdjacentToOtherCity(int v1, int v2) {
	AdjListNode * root = graph->arr[v1].head;
	bool check = false;

	cout << "City " << v1 << " is adjacent to city " << v2 << ": ";
	while (check == false) {
		if (root->city.getCityNumber == v2) {
			return true;
			check = true;
		}
		else {
			root = root->next;
		}
		if (root == NULL) {
			return false;
		}
	}
	delete root;
	root = NULL;
}

int GraphBuilder::CostFromOneCityToAnother(int v1, int v2) {
	AdjListNode * root = graph->arr[v1].head;
	bool check = false;

	if (IsCityAdjacentToOtherCity(v1, v2) != true) {
		cout << "These cities aren't next to each other!";
		return 0;
	}
	
	cout << "Cost from city " << v1 << " to adjacent city " << v2 << ": ";
	
	while (check == false) {
		if (root->city.getCityNumber == v2) {
			return root->cost;
			check = true;
		}
		else {
			root = root->next;
		}
		if (root == NULL) {
			return 0;
		}
	}
	delete root;
	root = NULL;
}

void GraphBuilder::SearchCity(string cityName) {

	cout << "Searching for a city in the map..." << endl;
	for (int i = 0; i < totalVertices; i++) {
		if (graph->arr[i].city.getCityName == cityName) {
			cout << "Node Found..." << endl;
			cout << "City Number: " << graph->arr[i].city.getCityNumber << endl;
			cout << "City Name: " << graph->arr[i].city.getCityName << endl;
			cout << "City Color: " << graph->arr[i].city.getCityColor << endl;
			cout << "Owned By: " << graph->arr[i].player.getName << endl;
		}
	}
}

void GraphBuilder::buildMap() {

	for (int i = 0; i < edges.size(); i++){
		//connect edges
		addEdge(graph, edges[i]);
	}
	
	/*
	addEdge(graph, 1, 2, 8);
	addEdge(graph, 1, 6, 4);
	addEdge(graph, 2, 3, 11);
	addEdge(graph, 2, 4, 11);
	addEdge(graph, 2, 12, 17);
	addEdge(graph, 2, 7, 8);
	addEdge(graph, 2, 6, 6);
	addEdge(graph, 3, 4, 8);
	addEdge(graph, 4, 5, 11);
	addEdge(graph, 4, 13, 11);
	addEdge(graph, 4, 12, 10);
	addEdge(graph, 5, 13, 14);
	addEdge(graph, 6, 7, 6);
	addEdge(graph, 7, 12, 19);
	addEdge(graph, 7, 11, 16);
	addEdge(graph, 7, 10, 18);
	addEdge(graph, 7, 9, 19);
	addEdge(graph, 7, 8, 6);
	addEdge(graph, 8, 9, 19);
	addEdge(graph, 9, 10, 15);
	addEdge(graph, 10, 11, 10);
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

	
	// careful not to add any dupilcate edges that we already defined
	*/
}


