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
	vector<Elektro> elektros;
	vector<City> citiesOwned;
	vector<RessourceToken> resources;


public:
    
	Player();
	Player(string name, string color);
	~Player();

	string getName();
	string getColor();
	vector<PowerPlant> getPowerPlant();
	vector<Elektro> getElektros();
	vector<RessourceToken> getResources();
	void addCity(City city);
	void addPowerPlant(PowerPlant p);
	void collectElektro(Elektro e);
	//void removeElektro(int quantity, int billValue);
	void toString();
};
