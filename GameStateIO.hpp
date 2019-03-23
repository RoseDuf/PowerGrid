

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
#include "GameState.hpp"

namespace GameStateIO {

	GameState readXmlFile(std::string filename);
	void writeXmlFile(GameState gameState);
}

#endif
