//
//  player.cpp
//  player
//
//  Copyright © 2019 Elsa Donovan. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <vector>
#include "player.hpp"


using namespace std;

//default constructor
Player::Player() {
    numCities = 0;
   
}

Player::~Player()
{
}

// parametrized constructor
Player::Player(string name){
    this-> name = name;
     numCities = 0;
}



void Player::toString(){

    cout << "Player name: " << name
    << "\nNumber of cities owned: " << numCities
    << "\nNumber of powerplants owned: " << PowerPlantsOwned.size() << "\nAmount of Elektro: " << wallet.size();
}
