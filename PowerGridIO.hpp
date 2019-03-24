

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
#include "GameState.hpp"

typedef std::tuple< std::vector<City>, std::vector<EdgeTriplet> > MapData;

namespace PowerGridIO {
    
    MapData getMapData(std::string mapFilename);
    GameState loadGame(std::string saveFilename);
    
    void saveGame(GameState gameState);
}

#endif
