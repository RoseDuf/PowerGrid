//(Rose, Elsa and Isabelle)

#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <vector>
#include "City.h"
#include "Player.hpp"
#include <tuple>

typedef std::tuple<City, City, int> EdgeTriplet;
typedef std::tuple<std::string, std::string, bool> AdjacentRegionsTriplet;
typedef std::tuple< std::vector<City>, std::vector<EdgeTriplet>, std::vector<AdjacentRegionsTriplet> > MapData;

class GameState {
private:
	int turnOfPlayer;
    std::vector<City> cities;
	std::vector<EdgeTriplet> edgeTriplets;
    std::vector<AdjacentRegionsTriplet> adjacentRegionsTriplets;
	std::vector<Player> players;
	
public:
	std::vector<City> getCities();
	void addCity(City cityToAdd);
	void addCities(std::vector<City> citiesToAdd);
	void setCities(std::vector<City> cities);
	GameState(); // temp
	GameState(int turnOfPlayer, std::vector<City> cities, std::vector<EdgeTriplet> edgeTriplets, std::vector<Player> players);
	std::vector< EdgeTriplet > getEdgeTriplets();
	void setEdgeTriplets(std::vector<EdgeTriplet> edgeTriplets);
	void addEdgeTriplets(std::vector<EdgeTriplet> additionalEdgeTriplets);
	void addEdgeTriplet(EdgeTriplet additionalEdgeTriplet);
	void setTurnOfPlayer(int turnOfPlayer);
	int getTurnOfPlayer();
	std::vector<Player> getPlayers();
	void setPlayers(std::vector<Player> players);
	void addPlayers(std::vector<Player> playersToAdd);
	void addPlayer(Player playerToAdd);
    
    std::vector<AdjacentRegionsTriplet> getAdjacentRegionsTriplets();
	void setAdjacentRegionsTriplets(std::vector<AdjacentRegionsTriplet> AdjacentRegionsTriplets);
	void addAdjacentRegionsTriplets(std::vector<AdjacentRegionsTriplet> additionalAdjacentRegionsTriplets);
	void addAdjacentRegionsTriplet(AdjacentRegionsTriplet additionalAdjacentRegionsTriplet);
    
    MapData getMapData();
    void setMapData(MapData mapData);
};

#endif
