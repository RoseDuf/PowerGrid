#include "GameState.hpp"

GameState::GameState() { // temp

}

std::vector<City> GameState::getCities() {
	return cities;
}

void GameState::addCity(City cityToAdd) {
	cities.push_back(cityToAdd);
}

void GameState::addCities(std::vector<City> citiesToAdd) {
	for (int i = 0; i < citiesToAdd.size(); i++) {
		cities.push_back(citiesToAdd.at(i));
	}
}

void GameState::setCities(std::vector<City> cities) {
	this->cities = cities;
}

GameState::GameState(int turnOfPlayer, std::vector<City> cities, std::vector<EdgeTriplet> edgeTriplets, std::vector<Player> playas)
	: turnOfPlayer(turnOfPlayer), cities(cities), edgeTriplets(edgeTriplets), players(playas) {}

void GameState::setEdgeTriplets(std::vector<EdgeTriplet> edgeTriplets) {
	this->edgeTriplets = edgeTriplets;
}

void GameState::addEdgeTriplets(std::vector< EdgeTriplet > additionalEdgeTriplets) {
	for (int i = 0; i < additionalEdgeTriplets.size(); i++) {
		this->edgeTriplets.push_back(additionalEdgeTriplets.at(i));
	}
}

void GameState::addEdgeTriplet(EdgeTriplet additionalEdgeTriplet) {
	this->edgeTriplets.push_back(additionalEdgeTriplet);
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
	for (int i = 0; i < playersToAdd.size(); i++) {
		players.push_back(playersToAdd.at(i));
	}
}

void GameState::addPlayer(Player playerToAdd) {
	players.push_back(playerToAdd);
}

MapData GameState::getMapData() {
    MapData mapData = MapData( getCities(), getEdgeTriplets(), getAdjacentRegionsTriplets() );
    return mapData;
}

void GameState::setMapData(MapData mapData) {
    setCities( std::get<0>(mapData) );
    setEdgeTriplets( std::get<1>(mapData) );
    setAdjacentRegionsTriplets( std::get<2>(mapData) );
}

std::vector<AdjacentRegionsTriplet> GameState::getAdjacentRegionsTriplets() {
    
    return adjacentRegionsTriplets;
}

void GameState::setAdjacentRegionsTriplets(std::vector<AdjacentRegionsTriplet> adjacentRegionsTriplets) {
    this->adjacentRegionsTriplets = adjacentRegionsTriplets;
}
    
void GameState::addAdjacentRegionsTriplets(std::vector<AdjacentRegionsTriplet> additionalAdjacentRegionsTriplets) {
 
    for(int i = 0; i < additionalAdjacentRegionsTriplets.size(); i++) {
        this->adjacentRegionsTriplets.push_back( additionalAdjacentRegionsTriplets.at(i) );
    }
}

void GameState::addAdjacentRegionsTriplet(AdjacentRegionsTriplet additionalAdjacentRegionsTriplet) {
    this->adjacentRegionsTriplets.push_back( additionalAdjacentRegionsTriplet );
}
