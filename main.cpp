
#include<iostream>
#include<cstdlib>
#include"GraphBuilder.h"
using namespace std;


int main() {
	GraphBuilder graph = GraphBuilder(42);
	graph.buildMap();
	//print the adjacency list representation of graph
	graph.printGraph();
}