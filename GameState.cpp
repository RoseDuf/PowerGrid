#include "GameState.hpp"

void GameState::setEdgeTriplets(std::vector<EdgeTriplet> edgeTriplets) {
    this->edgeTriplets = edgeTriplets;
}

void GameState::addEdgeTriplets(std::vector< EdgeTriplet > additionalEdgeTriplets) {
    for(int i = 0; i < additionalEdgeTriplets.size(); i++) {
        this->edgeTriplets.push_back( additionalEdgeTriplets.at(i) );
    }
}

void GameState::addEdgeTriplet(EdgeTriplet additionalEdgeTriplet) {
    this->edgeTriplets.push_back( additionalEdgeTriplet );
}

std::vector< EdgeTriplet > GameState::getEdgeTriplets() {
    return edgeTriplets;
}

void GameState::setTurnOfPlayer(int turnOfPlayer) {
    this->turnOfPlayer = turnOfPlayer;
}
int GameState::getTurnOfPlayer() {
    return turnOfPlayer;
}
std::vector<Player> GameState::getPlayers() {
    return players;
}

void GameState::setPlayers(std::vector<Player> players) {
    this->players = players;
}

void GameState::addPlayers(std::vector<Player> playersToAdd) {
    for(int i = 0; i < playersToAdd.size(); i++) {
        players.push_back( playersToAdd.at(i) );
    }
}

void GameState::addPlayer(Player playerToAdd) {
    players.push_back( playerToAdd );
}
