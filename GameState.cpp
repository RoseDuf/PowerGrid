#include "GameState.hpp"

void GameState::setEdgePairs(std::vector< std::pair<City, City> > edgePairs) {
    this->edgePairs = edgePairs;
}

void GameState::addEdgePairs(std::vector< std::pair<City, City> > additionalEdgePairs) {
    for(int i = 0; i < additionalEdgePairs.size(); i++) {
        this->edgePairs.push_back( additionalEdgePairs.at(i) );
    }
}

void GameState::addEdgePair(std::pair<City, City> additionalEdgePair) {
    this->edgePairs.push_back( additionalEdgePair );
}

std::vector< std::pair<City, City> > GameState::getEdgePairs() {
    return edgePairs;
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
