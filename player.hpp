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
    
   	 //vector<Elektro> elektros;
   	 Elektro wallet;
	vector<City> citiesOwned;
	vector<RessourceToken> resources;


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
	//vector<Elektro> getElektros();
	vector<RessourceToken> getResources();
	void addCity(City city);
	void addPowerPlant(PowerPlant p);
	//void addElektro(Elektro e);
	//void removeElektro(int quantity, int billValue);
	void toString();
};
