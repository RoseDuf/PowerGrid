//  player Header File

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "Elektro.hpp"
#include "City.h"

using namespace std;

class Player {
    
private:
    string name;
	string color;
	vector<PowerPlant> powerPlants;
    Elektro wallet;
	vector<City> citiesOwned;


public:
    
	Player();
	Player(string name, string color);
	~Player();
    
   	 void collectElektro(int _bill1, int _bill10, int _bill50);
   	 void spendElektros(int _bill1, int _bill10, int _bill50);
	//just prints the waller content
   	 void getWallet();
	//returns how much the players has
    int getTotalWallet();
	string getName();
	string getColor();
	vector<PowerPlant> getPowerPlant();

	void addCity(City city);
	vector<City> getCitiesOwned();
	void addPowerPlant(PowerPlant p);

	void toString();
};