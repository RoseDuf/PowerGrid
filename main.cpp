
#include<iostream>


using namespace std;
#include "PowerPlant.h"

int main() {
	/*
    GraphBuilder graph = GraphBuilder(42);
	graph.buildMap();
	//print the adjacency list representation of graph
	graph.printGraph();

	graph.SearchCity(0);

	std::cout << std::boolalpha;
	std::cout << graph.IsCityAdjacentToOtherCity(1, 3) <<endl;
	std::cout << graph.CostFromOneCityToAnother(1, 3) << endl;
     
     */
    
    //source:https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
    PowerPlant p = PowerPlant(23, 2, 1, "coal", "garbage");
    cout << "Ressource tokens of p :" << endl;

    string* ptr;
    ptr = p.getTypeRessourceTokenNeeded();
    for(int i = 0; i< 2; i++)
    {
        cout << *(ptr + i) << endl;
    }
    p.toString();
    
    return 0;
}