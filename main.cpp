
#include<iostream>
#include<cstdlib>
#include"GraphBuilder.h"
#include "GameStateIO.hpp"
#include "HelperFunctions.hpp"
using namespace std;


int main() {
	/*GraphBuilder graph = GraphBuilder(42);
	graph.buildMap();
	//print the adjacency list representation of graph
	graph.printGraph();*/
    
    //std::string str = "abcde";std::cout << HelperFunctions::chopStr(str, 1, 3) << std::endl;
    GameStateIO::readXmlFile("/home/deniz/kdevelop_projects/PowerGrid/powergrid_cities.map");
}
