//  player Header File

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "Elektro.hpp"
#include "City.h"
//#include "ResourceToken.hpp"

using namespace std;

class Player {
    
private:
    string name;
	string color;
	vector<PowerPlant> powerPlants;
    
   	//vector<Elektro> elektros;
   	Elektro wallet;
	vector<City> citiesOwned;
	//vector<ResourceToken> resources;
	int playerOrder;


public:
    
	Player();
	Player(string name, string color);
	Player(string name, string color, vector<PowerPlant> 
		powerPlant, Elektro wallet, vector<City> citiesOwned, 
		/*vector<ResourceToken> resources,*/ int playerOrder);
	~Player(); 
	Player(const Player &p2); //copy constructor
    
    
  	void collectElektro(int _bill1, int _bill10, int _bill50);
    void spendElektros(int _bill1, int _bill10, int _bill50);
	//just prints the waller content
   	void walletToString();
	//returns how much the players has
    int getTotalWallet();
	void setTotalWallet(Elektro w);

	string getName();
	void setName(string name);

	string getColor();
	void setColor(string color);

	vector<PowerPlant> getPowerPlant();
	void setPowerPlant(vector<PowerPlant> pp);

	//vector<Elektro> getElektros();
	//vector<ResourceToken> getResources();

	void addCity(City city);
	vector<City> getCitiesOwned();
	void setCitiesOwned(vector<City> c);

	int getplayerOrder();
	void setplayerOrder(int playerOrder);

	//to sort player's by the number of cities owned (to determine order)
	static bool compByCities(Player* a, Player* b){
		return b->citiesOwned.size() < a->citiesOwned.size();
	}
	static bool compByOrder(Player* a, Player* b) {
		return a->playerOrder < b->playerOrder;
	}
	static bool reverseOrder(Player* a, Player* b) {
		return b->playerOrder < a->playerOrder;
	}

	void addPowerPlant(PowerPlant p);
	//void addElektro(Elektro e);
	//void removeElektro(int quantity, int billValue);
	void toString();

	//task2 - step2 -> auctioning powerplants
	//void Pass(PowerPlant p);
	//void Auction(GameCard * p);

};