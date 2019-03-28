#include<iostream>
#include<cstdlib>
#include <utility>      // std::pair, std::get
#include <vector>
#include "GraphBuilder.h"
#include "PowerGridIO.hpp"
#include "City.h"
#include "player.hpp"
#include <limits.h>
#include <algorithm>
#include <set>
using namespace std;

/*
GraphBuilder::GraphBuilder(int tv) { // I DON'T THINK THAT THIS CONSTRUCTOR BEHAVES AS INTENDED!
totalVertices = tv;
graph = createGraph(totalVertices, std::get<0>(mapData));
edges = std::get<1>(mapData);
//totalVertices = tv;
//graph = createGraph(totalVertices, gameState.getCities());
//edges = gameState.getEdgeTriplets();
}
*/

GraphBuilder::GraphBuilder(int tv, std::string mapFilename) {
	totalVertices = tv;
	mapData = PowerGridIO::getMapData(mapFilename);
	graph = createGraph(totalVertices, std::get<0>(mapData)); // std::get<0>(mapData) is std::vector<City>
	edges = std::get<1>(mapData); // std::get<1>(mapData) is std::vector<EdgeTriplet> //gameState.getEdgeTriplets();
	/*totalVertices = tv;
	gameState = PowerGridIO::loadGame(file);
	graph = createGraph(totalVertices, gameState.getCities());
	edges = gameState.getEdgeTriplets();*/
	buildMap();
}

GraphBuilder::~GraphBuilder() {
	delete graph;
	graph = NULL;
}

int GraphBuilder::getTotalVertices() {
	return totalVertices;
}

void GraphBuilder::setTotalVertices(int tv) {
	totalVertices = tv;
}

vector<vector<int>> GraphBuilder::getConnected() {
	return connected;
}

//create a new node
GraphBuilder::AdjListNode * GraphBuilder::newAdjListNode(int cityno, string cityname, string citycolor, int cost) {

	AdjListNode * nptr = new AdjListNode;

	nptr->city = City(cityno, cityname, citycolor, true);
	nptr->cost = cost;
	nptr->next = NULL;
	return nptr;
}

//function to create a graph of v vertices
GraphBuilder::Graph * GraphBuilder::createGraph(int totalVertices, vector<City> cities) {

	Graph * graph = new Graph;

	graph->v = totalVertices;

	for (int i = 0; i < totalVertices; i++) {
		CityList cl = CityList();
		//create an array of adjacency list. size of array - V
		graph->arr.push_back(cl);
	}

	//initialize with NULL (e.g root=NULL)
	for (int i = 0; i < totalVertices; i++) {
		graph->arr[i].city = City();
		graph->arr[i].city.setCityNumber(cities[i].getCityNumber());
		graph->arr[i].city.setCityName(cities[i].getCityName());
		graph->arr[i].city.setCityColor(cities[i].getCityColor());
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

void GraphBuilder::addConnectedCitiestoVector() {
	for (int i = 0; i<graph->v; i++) {
		AdjListNode * root = graph->arr[i].head;

		connected.push_back(std::vector<int>());
		//loop over each node in list
		while (root != NULL) {
			connected[i].push_back(root->city.getCityNumber());
			root = root->next;
		}

		//delete every root pointer created
		root = NULL;
	}
}

void GraphBuilder::printGraph() {

	//loop over each adjacent list
	for (int i = 0; i<graph->v; i++) {

		AdjListNode * root = graph->arr[i].head;

		if (root != NULL) {
			if (root->city.isAvailable())
				cout << "City " << i << " is available." << endl;
			else if (!root->city.isAvailable())
				cout << "City " << i << " is NOT available." << endl;

			//loop over each node in list
			while (root != NULL) {
				cout << i << " to " << root->city.getCityNumber() << " costs: " << root->cost;
				if (root->city.isAvailable())
					cout << " /// City: " << root->city.getCityNumber() << " is available." << endl;
				else
					cout << " /// City: " << root->city.getCityNumber() << " is NOT available." << endl;

				root = root->next;
			}
		}
		cout << endl;

		//delete every root pointer created
		root = NULL;
	}
}

void GraphBuilder::printAvailableCities() {
	//loop over each adjacent list

	for (int i = 0; i<graph->v; i++) {
		if (graph->arr[i].city.isAvailable())
			cout << graph->arr[i].city.getCityName() << endl;
	}
}

void GraphBuilder::removeRegions(string color) {

	//first, set availability of all edges of a certain color in the adjacency list to FALSE
	for (int i = 0; i<graph->arr.size(); i++) {

		AdjListNode * root = graph->arr[i].head;

		while (root != NULL) {
			if (root->city.getCityColor() == color) {
				root->city.setAvailable(false);
			}
			root = root->next;
		}

		//delete every root pointer created
		root = NULL;
	}

	//second, set availability of all cities of certain color in the CityList to FALSE
	for (int i = 0; i < graph->arr.size(); i++) {
		if (graph->arr[i].city.getCityColor() == color) {
			graph->arr[i].city.setAvailable(false);
		}
	}

}

//might not need this function... Leaving it commented out just in case. Who knows ?\_("/)_/?
City GraphBuilder::findCityByName(string name) {
	City city;
	for (int i = 0; i < totalVertices; i++) {
		if (graph->arr[i].city.getCityName() == name) {
			return graph->arr[i].city;
		}
	}
	cout << "No city of this name found in the map..." << endl;
}

//function to add players to "cities"(aka Nodes) in the physical map
//and updates Player info at the same time
//USE THIS FUNCTION TO ADD CITIES TO PLAYERS DURING GAMEPLAY
bool GraphBuilder::add_CityToPlayer_and_PlayerToMap(Player * pl, string name) {
	City c = City();

	for (int i = 0; i < totalVertices; i++) {
		//so apparently checking if graph->arr[i].city.getAvailable() == true doesn't work...
		if ((graph->arr[i].city.getCityName() == name) && (graph->arr[i].city.isAvailable())) {

			c = graph->arr[i].city; //find the desired city by its name
			if (graph->arr[i].player.size() < 4) {
				graph->arr[i].player.push_back(*pl); //add Player to the physical map
				pl->addCity(c);	//add/update new City object to Player "cities" attribute 
				return true;
			}
			else {
				cout << "--------Can't add player to " << graph->arr[i].city.getCityName() << " because it is too full! (already has 3 players)--------" << endl;
				return false;
			}
		}
		else if ((graph->arr[i].city.getCityName() == name) && (!graph->arr[i].city.isAvailable())) {
			cout << "--------" << graph->arr[i].city.getCityName() << " is not available for purchase--------" << endl;
			return false;
		}
	}
}

//This function is ONLY used for reloading a gamestate
//DO NOT USE THIS METHOD FOR GAMEPLAY
//FOR LOADING GAMSTATE PURPOSES ONLY!
void GraphBuilder::AddPlayerToMap(Player * pl) {
	vector<City> citiesOwned = pl->getCitiesOwned();
	std::sort(citiesOwned.begin(), citiesOwned.end(), City::compare);

	//update the map
	for (int i = 0; i < citiesOwned.size(); i++) {
		for (int j = 0; j < graph->arr.size(); j++) {
			if (graph->arr[j].city.getCityNumber() == citiesOwned[i].getCityNumber() /*&& (graph->arr[j].city.isAvailable())*/) { //we would have to assume that the cities a player owns are all available
				graph->arr[j].player.push_back(*pl); //add player to Nodes/Cities on the map
			}
		}
	}
}

//check how many players own a city (returns int)
int  GraphBuilder::HowManyPlayersAreInCity(string cityName) {
	cout << "Searching for a city in the map..." << endl;
	for (int i = 0; i < totalVertices; i++) {
		if (graph->arr[i].city.getCityName() == cityName) {
			cout << "There are " << graph->arr[i].player.size() << " players already in this city." << endl;
			return graph->arr[i].player.size();
		}
	}
}

//Function that returns a vector of "cities"(Nodes) that have a player
vector<City> GraphBuilder::FindCitiesOwnedByPlayer(Player * pl) {

	vector<City> citiesOwned;

	for (int i = 0; i < totalVertices; i++) {
		for (int j = 0; j < graph->arr[i].player.size(); j++) {
			if (graph->arr[i].player[j].getName() == pl->getName()) {
				citiesOwned.push_back(graph->arr[i].city);
			}
		}
		/*else
		cout << "Player:" << pl->getName() << ", Color: " << pl->getColor()
		<< ", is not in City: " << graph->arr[i].city.getCityName() << endl;
		*/
	}
	return citiesOwned;
}

//error handler to check if a vertex is connected to another
bool GraphBuilder::IsCityAdjacentToOtherCity(string city1, string city2) {
	AdjListNode * root = NULL;
	for (int v1 = 0; v1 < totalVertices; v1++) {
		if (graph->arr[v1].city.getCityName() == city1) {
			root = graph->arr[v1].head;
		}
	}

	bool check = false;

	while (check == false) {
		if (root == NULL) {
			check = false;
			break;
		}
		if (root->city.getCityName() == city2)
			check = true;
		else
			root = root->next;
	}

	//use smart pointers
	root = NULL;

	if (check == true) {
		cout << "City " << city1 << " is adjacent to city " << city2 << endl;
		return true;
	}
	else {
		cout << "City " << city1 << " is NOT adjacent to city " << city2 << endl;
		return false;
	}
}

//function to look at the cost from one city to another (must be adjacent)
//will further be used for the gameplay. (i.e. computing the cost of connections between cities to buy)
int GraphBuilder::CostFromOneCityToAnother(string city1, string city2) {
	AdjListNode * root = NULL;
	for (int v1 = 0; v1 < totalVertices; v1++) {
		if (graph->arr[v1].city.getCityName() == city1) {
			root = graph->arr[v1].head;
		}
	}
	bool check = false;

	//check if the cities are connected first
	if (!IsCityAdjacentToOtherCity(city1, city2)) {
		cout << "These cities aren't next to each other!";
		return 100;
	}

	while (check == false) {
		if (root == NULL) {
			check = false;
			break;
		}
		if (root->city.getCityName() == city2)
			check = true;
		else
			root = root->next;
	}

	if (check == true) {
		cout << "Cost from city " << city1 << " to adjacent city " << city2 << ": ";
		cout << root->cost << endl;
		return root->cost;
	}
	//use smart pointers
	root = NULL;

}

//prints out information within a node of the map
void GraphBuilder::SearchCity(string cityName) {
	cout << endl;
	cout << "Searching for a city in the map..." << endl;
	for (int i = 0; i < totalVertices; i++) {

		if (graph->arr[i].city.getCityName() == cityName) {
			cout << "Node Found..." << endl;
			cout << "City Number: " << graph->arr[i].city.getCityNumber() << endl;
			cout << "City Name: " << graph->arr[i].city.getCityName() << endl;
			cout << "City Color: " << graph->arr[i].city.getCityColor() << endl;
			std::cout << std::boolalpha;
			cout << "City Availability: " << graph->arr[i].city.isAvailable() << endl;
			if (graph->arr[i].player.size() == 0) {
				cout << "Owned By: No One" << endl;
			}
			else {
				for (int j = 0; j < graph->arr[i].player.size(); j++) {
					cout << "Owned By: " << graph->arr[i].player[j].getName() << ", " << graph->arr[i].player[j].getColor() << endl;
				}
			}

			//this is kinda useless, was only there for assignment 1
			//cout << "---------------Contains---------------" << endl;
			//for (int j = 0; j < graph->arr[i].powerplants.size(); j++) {
			//	graph->arr[i].powerplants[j].toString();
			//}
			//for (int j = 0; j < graph->arr[i].resources.size(); j++) {
			//	graph->arr[i].resources[j].toString();
			//}

			//cout << endl;

			//for (int j = 0; j < graph->arr[i].elektros.size(); j++) {
			//	graph->arr[i].elektros[j].toString();
			//}

			//cout << graph->arr[i].player.
		}
	}
}

//Adds Elektros to the City Node
/*
void GraphBuilder::add_ElektrosToCity(Elektro el, string name) {
for (int i = 0; i < totalVertices; i++) {
if (graph->arr[i].city.getCityName() == name) {
graph->arr[i].elektros.push_back(el); //add PowerPlant to the physical map
}
}
}*/

//Adds Resources to the City Node
//void GraphBuilder::add_ResourcesToCity(ResourceToken rt, string name) {
//	for (int i = 0; i < totalVertices; i++) {
//		if (graph->arr[i].city.getCityName() == name) {
//			graph->arr[i].resources.push_back(rt); //add PowerPlant to the physical map
//		}
//	}
//}

//Adds PowerPlants to the City Node
/*
void GraphBuilder::add_PowerPlantToCity(PowerPlant pp, string name) {
for (int i = 0; i < totalVertices; i++) {
if (graph->arr[i].city.getCityName() == name) {
graph->arr[i].powerplants.push_back(pp); //add PowerPlant to the physical map
}
}
}*/

//test case to test if the number of cities from the file matches the number of nodes in the map
bool GraphBuilder::test_SizeOfMap_and_FileMap() {

	vector<City> citiesfile = std::get<0>(mapData);
	if (citiesfile.size() == totalVertices) {
		cout << "Number of cities in physical map and map from file match!" << endl;
		return true;
	}
	else {
		cout << "Oops..." << endl;
		cout << "Number of cities in physical map and map from file DON'T match!" << endl;
		cout << "Probably missing nodes or there are extra ones." << endl;
		return false;
	}
}

bool GraphBuilder::hasDuplicateEdge() {
	bool check = true;

	for (int i = 0; i < connected.size(); i++) {
		std::sort(connected[i].begin(), connected[i].end());
		for (int j = 1; j < connected[i].size(); j++) {
			if (connected[i][j - 1] == connected[i][j]) {
				check = false;
				break;
			}
			else {
				check = true;
			}
		}
		if (check == false) {
			break;
		}
	}

	if (check == true) {
		cout << "No duplicate edges" << endl;
		return false; // has no duplicate edge(s)
	}
	else {
		cout << "Duplicate Edge exists!!! " << endl;
		return true; // has at least one duplicate edge
	}
}

bool GraphBuilder::hasMissingEdge() {
	bool check = true;

	for (int i = 0; i < connected.size(); i++) {
		if (connected[i].size() == 0) {
			check = false;
			break;
		}
		else if (connected[i].size() > 0) {
			check = true;
		}
	}

	if (check == true) {
		cout << "No disconnected cities." << endl;
		return false; // does not have any missing edges
	}
	else {
		cout << "Disconnected Edge Exists!" << endl;
		return true; // has at least one missing edge
	}
}

//adds all the connections by using the vector of "EdgeTriplet" edges
void GraphBuilder::buildMap() {

	for (int i = 0; i < edges.size(); i++) {
		//connect edges
		addEdge(graph, edges[i]);
	}

	addConnectedCitiestoVector();

	/*
	bool check1, check2;
	check1 = test_Duplicate_Edges();
	check2 = test_MissingEdges();
	if (check1 == false || check2 == false) {
	cout << "Invalid Map!" << endl;
	delete graph;
	graph = NULL;
	}
	*/
	// careful not to add any dupilcate edges that we already defined
}

/*void GraphBuilder::populateAllRegionColors() {

	std::vector<AdjacentRegionsTriplet> tempArts = std::get<2>(mapData);
	std::set<std::string> tempAllRegionColors;


	for (int i = 0; i < tempArts.size(); i++) {
		AdjacentRegionsTriplet currentArt = tempArts.at(i);
		std::string col0 = std::get<0>(currentArt);
		std::string col1 = std::get<1>(currentArt);

		tempAllRegionColors.insert(col0);
		tempAllRegionColors.insert(col1);
	}

	ALL_REGION_COLORS.assign(tempAllRegionColors.begin(), tempAllRegionColors.end());
}*/

vector<AdjacentRegionsTriplet> GraphBuilder::getChosenAdjacentRegionsTriplets(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols) {
	std::set<AdjacentRegionsTriplet> tempArts; // use a set to easily remove duplicates

	for (int i = 0; i < arts.size(); i++) {
		string col0 = get<0>(arts.at(i));
		string col1 = get<1>(arts.at(i));
		//bool b2 = get<2>( arts.at(i) );
		for (int j = 0; j < chosenRegCols.size(); j++) {
			for (int k = 0; k < chosenRegCols.size(); k++) {
				if ((col0 == chosenRegCols.at(j) && col1 == chosenRegCols.at(k)) || ((col1 == chosenRegCols.at(j) && col0 == chosenRegCols.at(k)))) {
					tempArts.insert(arts.at(i));
				}
			}
		}
	}

	std::vector<AdjacentRegionsTriplet> tempArts2;

	for (auto it = tempArts.begin(); it != tempArts.end(); it++) {
		tempArts2.push_back(*it);
	}

	return tempArts2;
}

bool GraphBuilder::hasPath(string begCol, string endCol, vector<AdjacentRegionsTriplet> arts, int pathSize, const int MAX_PATH_SIZE) {

	if (begCol == endCol) {
		return true;
	}

	if (pathSize > MAX_PATH_SIZE) {
		return false;
	}
	bool previousPathFound = false;
	for (int i = 0; i < arts.size(); i++) {

		string col0 = get<0>(arts.at(i));
		string col1 = get<1>(arts.at(i));
		bool b2 = get<2>(arts.at(i));

		if (((begCol == col0 && endCol == col1) || (begCol == col1 && endCol == col0)) && b2 == true) {
			return true;
		}

		if (begCol == col0 && endCol != col1 && b2 == true) {
			//return hasPath(col1,endCol, arts, ++pathSize, MAX_PATH_SIZE);
			previousPathFound = previousPathFound || hasPath(col1, endCol, arts, ++pathSize, MAX_PATH_SIZE);
		}

		if (begCol == col1 && endCol != col0 && b2 == true) {
			//return hasPath(col0,endCol, arts, ++pathSize, MAX_PATH_SIZE);
			previousPathFound = previousPathFound || hasPath(col0, endCol, arts, ++pathSize, MAX_PATH_SIZE);
		}

		if (previousPathFound == true) {
			return true;
		}
	}

	return false;
}

bool GraphBuilder::areChosenRegionsConnected(vector<string> chosenRegCols) {
	const int MAX_PATH_SIZE = chosenRegCols.size(); /* This is the smallest value that's large enough because each color in chosenRegCols has one path to each color, including itself, to test. */
	vector<AdjacentRegionsTriplet> arts = std::get<2>(this->mapData);

	return areChosenRegionsConnected(arts, chosenRegCols, MAX_PATH_SIZE);
}

bool GraphBuilder::areChosenRegionsConnected(vector<AdjacentRegionsTriplet> arts, vector<string> chosenRegCols, const int MAX_PATH_SIZE) {

	// throw invalid chosenRegCols size or something like that // TODO

	for (int i = 0; i < chosenRegCols.size(); i++) {
		for (int j = 0; j < chosenRegCols.size(); j++) {
			if (!hasPath(chosenRegCols.at(i), chosenRegCols.at(j), getChosenAdjacentRegionsTriplets(arts, chosenRegCols), 0, MAX_PATH_SIZE)) {
				return false;
			}
		}
	}
	return true;
}

bool GraphBuilder::eachRegionHasSevenCities() {
	int counter = 0;

	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; i < cities.size(); j++) {
			cities.at(j).getCityColor();
			counter++;
		}
		if (counter != 7) {
			return false;
		}
		counter = 0;
	}

	return true;
}

/* ----------------------------------------------------------------------------------------------------------
Dijkstra Search algorithm source code taken and modified from:
https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
----------------------------------------------------------------------------------------------------------
*/
/*
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
minHeap->array = new MinHeapNode *[capacity];
return minHeap;
}
//function to swap two nodes of min heap. Needed for min heapify
void GraphBuilder::swapMinHeapNode(struct MinHeapNode ** a, struct MinHeapNode ** b) {
struct MinHeapNode * t = *a;
*a = *b;
*b = t;
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
int v = pCrawl->city.getCityNumber();
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
*/
// ----------------------------------------------------------------------------------------------------------
