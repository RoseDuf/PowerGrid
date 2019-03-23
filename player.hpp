//  player Header File

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "Elektro.hpp"
#include "City.h"
#include "ResourceToken.hpp"

using namespace std;

class Player {
    
private:
    string name;
	string color;
	vector<PowerPlant> powerPlants;
    
   	//vector<Elektro> elektros;
   	Elektro wallet;
	vector<City> citiesOwned;
	vector<ResourceToken> resources;
	int playerOrder;


public:
    
	Player();
	Player(string name, string color);
	Player(string name, string color, vector<PowerPlant> 
		powerPlant, Elektro wallet, vector<City> citiesOwned, 
		vector<ResourceToken> resources, int playerOrder);
	~Player();
	Player(const Player &p2);
    
    
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
	vector<ResourceToken> getResources();
	void addCity(City city);
	vector<City> getCitiesOwned();

	int getplayerOrder();
	void setplayerOrder(int playerOrder);

	static bool compById(const Player* a, const Player* b){
		return a->citiesOwned.size() < b->citiesOwned.size();
	}

	void addPowerPlant(PowerPlant p);
	//void addElektro(Elektro e);
	//void removeElektro(int quantity, int billValue);
	void toString();
};

/*//  player Header File

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "ElektroBill.hpp"
#include "City.h"
#include "RessourceToken.h"

using namespace std;

class Player {
    
private:
    	string name;
	string color;
	vector<PowerPlant> powerPlants;
<<<<<<< HEAD
    
   	 //vector<Elektro> elektros;
   	 Elektro wallet;
=======
	vector<ElektroBill> elektros;
>>>>>>> UpstreamGraphFixingBranch
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
<<<<<<< HEAD
	vector<PowerPlant> getPowerPlant();
	//vector<Elektro> getElektros();
	vector<RessourceToken> getResources();
	void addCity(City city);
	void addPowerPlant(PowerPlant p);
	//void addElektro(Elektro e);
=======
	vector<PowerPlant> getPowerPlants();
	vector<ElektroBill> getElektros();
	vector<RessourceToken> getResources();
	void addCity(City city);
	void addPowerPlant(PowerPlant p);
	void collectElektro(ElektroBill e);
>>>>>>> UpstreamGraphFixingBranch
	//void removeElektro(int quantity, int billValue);
	void toString();
};
*/
