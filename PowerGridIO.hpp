//(Elsa)

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
#include "GameState.hpp"

namespace PowerGridIO {
    
    MapData getMapData(std::string mapFilename);
    GameState loadGame(std::string saveFilename);
    
    void saveGame(GameState gameState);
}

#endif
