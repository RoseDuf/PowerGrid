#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <vector>
#include "City.h"
#include "player.hpp"
#include <tuple>

typedef std::tuple<City,City,int> EdgeTriplet;

class GameState {
    private:
        int turnOfPlayer;
        std::vector< EdgeTriplet > edgeTriplets;
        std::vector<Player> players;
    public:
        std::vector< EdgeTriplet > getEdgeTriplets();
        void setEdgeTriplets(std::vector< EdgeTriplet > edgeTriplets);
        void addEdgeTriplets(std::vector< EdgeTriplet > additionalEdgeTriplets);
        void addEdgeTriplet(EdgeTriplet additionalEdgeTriplet);
        void setTurnOfPlayer(int turnOfPlayer);
        int getTurnOfPlayer();
        std::vector<Player> getPlayers();
        void setPlayers(std::vector<Player> players);
        void addPlayers(std::vector<Player> playersToAdd);
        void addPlayer(Player playerToAdd);
};

#endif
