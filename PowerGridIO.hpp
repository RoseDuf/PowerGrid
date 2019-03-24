

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
#include "GameState.hpp"

namespace PowerGridIO {
    
    MapData getMapData(std::string filename);
    GameState loadGame(std::string filename);
    
    void saveGame(GameState gameState);
}

#endif
