#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <vector>
#include "City.h"
#include "player.hpp"

class GameState {
    private:
        int turnOfPlayer;
        std::vector< std::pair<City, City> > edgePairs;
        std::vector<Player> players;
    public:
        std::vector< std::pair<City, City> > getEdgePairs();
        void setEdgePairs(std::vector< std::pair<City, City> > edgePairs);
        void addEdgePairs(std::vector< std::pair<City, City> > additionalEdgePairs);
        void addEdgePair(std::pair<City, City> additionalEdgePair);
        void setTurnOfPlayer(int turnOfPlayer);
        int getTurnOfPlayer();
        std::vector<Player> getPlayers();
        void setPlayers(std::vector<Player> players);
        void addPlayers(std::vector<Player> playersToAdd);
        void addPlayer(Player playerToAdd);
};

#endif
