

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
#include "GameState.hpp"

namespace GameStateIO {
    
    GameState loadGame(std::string filename);
    void saveGame(GameState gameState);
}

#endif
