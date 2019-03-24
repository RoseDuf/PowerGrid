#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <vector>
#include "City.h"
#include "player.hpp"
#include <tuple>

typedef std::tuple<City, City, int> EdgeTriplet;
typedef std::tuple< std::vector<City>, std::vector<EdgeTriplet> > MapData;

class GameState {
private:
	int turnOfPlayer;
	std::vector< EdgeTriplet > edgeTriplets;
	std::vector<Player> players;
	std::vector<City> cities;
public:
	std::vector<City> getCities();
	void addCity(City cityToAdd);
	void addCities(std::vector<City> citiesToAdd);
	void setCities(std::vector<City> cities);
	GameState(); // temp
	GameState(int turnOfPlayer, std::vector<City> cities, std::vector<EdgeTriplet> edgeTriplets, std::vector<Player> players);
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
    MapData getMapData();
    void setMapData(MapData mapData);
};

#endif
