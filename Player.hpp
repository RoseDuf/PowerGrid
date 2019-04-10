//  player Header File

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <cstdlib>
#include "PowerPlant.hpp"
#include "Elektro.hpp"
#include "City.h"
//#include "ResourceToken.hpp"

using namespace std;

class Player {

private:
	string name;
	string color;
	vector<PowerPlant*> powerPlants;
    
   	//vector<Elektro> elektros;
   	Elektro wallet;
	vector<City> citiesOwned;
	//vector<ResourceToken> resources;
	int playerOrder;

	int numCitiesOwned = 0;
	int numPPOwned = 0;

	int houses;

public:

	Player();
	Player(string name, string color);
	Player(string name, string color, vector<PowerPlant*> 
		powerPlant, Elektro wallet, vector<City> citiesOwned, int playerOrder);
	~Player(); 
	Player(const Player &p2); //copy constructor
    
    
  	void collectElektro(int _bill1, int _bill10, int _bill50);
    void spendElektros(int _bill1, int _bill10, int _bill50);
	//just prints the waller content
   	void walletToString();
	//returns how much the players has
    int getTotalWallet() const;
	void setTotalWallet(Elektro w);

	string getName();
	void setName(string name);

	string getColor();
	void setColor(string color);

	vector<PowerPlant*> getPowerPlants() const;
	void setPowerPlant(vector<PowerPlant*> pp);

	int getNumCitiesOwned() const;
	int getNumPPOwned() const;

	void addCity(City city);
	vector<City> getCitiesOwned();
	void setCitiesOwned(vector<City> c);

	int getRemainingHouses();
	void setHouses(int houses);

	int getplayerOrder();
	void setplayerOrder(int playerOrder);

	void addPowerPlant(PowerPlant* p);

	void powerCity(City city, PowerPlant* powerplant, string type);
	int getCitiesPowered();
	//setting powered back to false as we are starting another round in the game
	void setCitiesPowered();
	int getTotalCoal();
	int getTotalOil();
	int getTotalGarbage();
	int getTotalUranium();
    void removePowerPlant(PowerPlant* powerPlant);
    void removePowerPlant(int powerPlantCardNumber);

	void addPowerPlant(PowerPlant p);
	//void addElektro(Elektro e);
	//void removeElektro(int quantity, int billValue);
	void toString();

	//to sort player's by the number of cities owned (to determine order)
	static bool compByCities(const Player* a, const Player* b) {
		return b->citiesOwned.size() < a->citiesOwned.size();
	}
	static bool compByOrder(const Player* a, const Player* b) {
		return a->playerOrder < b->playerOrder;
	}
	static bool reverseOrder(const Player* a, const Player* b) {
		return b->playerOrder < a->playerOrder;
	}
};

#endif
