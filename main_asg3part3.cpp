
#include <iostream>
#include "PowerGridIO.hpp"
#include "GraphBuilder.h"

int main() {
    std::cout << "Hello" << std::endl;
    std::string mapFilename = "germany.map";
    MapData mapData = PowerGridIO::getMapData(mapFilename);
    GraphBuilder g(std::get<0>(mapData).size(), mapFilename);
    std::cout << g.eachRegionHasSevenCities() << std::endl;
    std::cout << g.isValidGraph() << std::endl;
    return 0;
}

