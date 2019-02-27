
#include<iostream>
#include<cstdlib>
#include"GraphBuilder.h"
using namespace std;


int main() {
	GraphBuilder graph = GraphBuilder(42);
	graph.buildMap();
	//print the adjacency list representation of graph
	graph.printGraph();

	graph.SearchCity(0);

	std::cout << std::boolalpha;
	std::cout << graph.IsCityAdjacentToOtherCity(1, 3) <<endl;
	std::cout << graph.CostFromOneCityToAnother(1, 3) << endl;
}