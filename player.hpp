//
//  player.hpp
//  player Header File
//
//  Copyright © 2019 Elsa Donovan. All rights reserved.
//

#pragma once
#include <iostream>
#include <cstdlib>
#include "PowerPlant.h"
#include "Elektro.h"
#include "City.h"

using namespace std;

class Player {
    
private:
    
    string name;
    int numCities;
    vector<PowerPlant> PowerPlantsOwned;
    vector<Elektro> wallet;
    vector<City> cities;
   

public:
 
    Player();
    Player(string name);
    ~Player();

    string getName(){
        return name;
    }
    
    //Adds city to Player's vector of cities
   void addCity(string cityName, string cityColor) {
       
       //going to fix this***
       //added all the attributes for city object**
       //cities.push_back(cityName, cityColor);
    }
    
    //mutator method for number of cities player owns
    void setNumCities(int numCities){
         this->numCities = numCities;
    }
    
    vector<City> getCitiesOwned()
    {
        return cities;
    }
    
    //add a PowerPlant to PowerPlantsOwned
    void addPowerPlant(PowerPlant p){
        PowerPlantsOwned.push_back(p);
    }
    
    //initialize Elektro amount in Player's wallet
    void setElektro(int quantity, int billValue){
    }
    
    //Add Elektro amount to Player's Wallet
    void CollectElektro(int quantity, int billValue){
        wallet.push_back(Elektro(quantity, billValue));
    }
    
    //string method for Player object
    void display();
    
};

