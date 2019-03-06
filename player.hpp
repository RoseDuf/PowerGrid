//  player Header File

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "Elektro.h"
#include "City.h"
#include "RessourceToken.h"

using namespace std;

class Player {
    
private:
    string name;
	string color;
    vector<PowerPlant> powerPlants;
    //Elektro elektros;
	int elektros;
	vector<City> citiesOwned;
	//vector<RessourceToken> resources;


public:
    Player();
    Player(string name, string color);
	~Player();

	string getName();
	string getColor();
	vector<PowerPlant> getPowerPlant();
	void addCity(City city);
	void addPowerPlant(PowerPlant p);
	//void addElektro(int quantity, int billValue);
	//void removeElektro(int quantity, int billValue);
	void toString();
};
