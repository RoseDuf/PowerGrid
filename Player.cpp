//
//  player.cpp
//  player
//

#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;

Player::Player() {
	name = "No Name";
	color = "BLANK";
	playerOrder = 0;
}

Player::Player(string name, string color) {
	this->name = name;
	this->color = color;
	wallet = Elektro(10, 4, 0);
	houses = 22;
}

Player::Player(string name, string color, vector<PowerPlant*>
	powerPlants, Elektro wallet, vector<City> cities, int playerOrder) {
	this->name = name;
	this->color = color;
    this->powerPlants = powerPlants;
	this->wallet = wallet;
	this->citiesOwned = cities;
	this->playerOrder = playerOrder;
	houses = 22;
}

Player::~Player() {}

Player::Player(const Player &p2) {
	name = p2.name; 
	color = p2.color;
	wallet = p2.wallet;
	citiesOwned = p2.citiesOwned;
	//resources = p2.resources;
	playerOrder = p2.playerOrder;
}

void Player::setWin(bool t)
{
	hasWon = t;
}
bool Player::getWin()
{
	return hasWon;
}
string Player::getName() const {
	return name;
}
void Player::setName(string n) {
	name = n;
}

string Player::getColor() const {
	return color;
}
void Player::setColor(string c) {
	color = c;
}

vector<PowerPlant*> Player::getPowerPlants() const {
	return powerPlants;
}
void Player::setPowerPlant(vector<PowerPlant*> pp) {
	powerPlants = pp;
}
void Player::addPowerPlant(PowerPlant* p) {
	powerPlants.push_back(p);
}

//vector<ResourceToken> Player::getResources() {
//	return resources;
//}

vector<City> Player::getCitiesOwned() const {
	return citiesOwned;
}
void Player::setCitiesOwned(vector<City> c) {
	citiesOwned = c;
}
void Player::addCity(City city) {
	citiesOwned.push_back(city);
}

void  Player::collectElektro(int _bill1, int _bill10, int _bill50)
{
	wallet.addElektros(_bill1, _bill10, _bill50);
}
void Player::spendElektros(int _bill1, int _bill10, int _bill50)
{
	wallet.spendElektros(_bill1, _bill10, _bill50);
}

void  Player::walletToString() {
	wallet.toString();
}
int  Player::getTotalWallet() const {
	return wallet.getTotalBalance();
}
void Player::setTotalWallet(Elektro w) {
	wallet = w;
}

int Player::getplayerOrder() const {
	return playerOrder;
}
void Player::setplayerOrder(int t) {
	playerOrder = t;
}

int Player::getRemainingHouses() const {
	return houses - citiesOwned.size();
}
void Player::setHouses(int h) {
	houses = h;
}

int Player::getNumCitiesOwned() const {
	return numCitiesOwned;
}

int Player::getNumPPOwned() const {
	return numPPOwned;
}

void Player::powerCity(City city, PowerPlant* powerplant, string type) {
	city.setPoweredState(true);
	powerplant->powerCity(type);
}

/* I think this method is both buggy and outdated.
    int Player::getCitiesPowered() const {
	int temp = 0;
	for (int i = 0; i < citiesOwned.size(); i++)
	{
		if (citiesOwned[i].getPoweredState()) temp++;
	}
	return temp;
}*/

//setting powered back to false as we are starting another round in the game
void Player::setCitiesPowered() {
	for (int i = 0; i < citiesOwned.size(); i++)
	{
		citiesOwned[i].setPoweredState(false);
	}
}

int  Player::getTotalCoalStocked() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTStocked("coal");
	}
	return temp;
}
int  Player::getTotalOilStocked() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTStocked("oil");
	}
	return temp;
}
int  Player::getTotalGarbageStocked() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTStocked("garbage");
	}
	return temp;
}
int  Player::getTotalUraniumStocked() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTStocked("uranium");
	}
	return temp;
}

int  Player::getTotalCoalNeeded() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTNeeded("coal");
	}
	return temp;
}
int  Player::getTotalOilNeeded() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTNeeded("oil");
	}
	return temp;
}
int  Player::getTotalGarbageNeeded() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTNeeded("garbage");
	}
	return temp;
}
int  Player::getTotalUraniumNeeded() const {
	int temp = 0;
	for (int i = 0; i < powerPlants.size(); i++)
	{
		temp += powerPlants[i]->getRTNeeded("uranium");
	}
	return temp;
}

int  Player::getTotalCoalStockable() const {
    return 2*getTotalCoalNeeded();
}

int  Player::getTotalOilStockable() const {
    return 2*getTotalOilNeeded();
}

int  Player::getTotalGarbageStockable() const {
    return 2*getTotalGarbageNeeded();
}

int  Player::getTotalUraniumStockable() const {
    return 2*getTotalUraniumNeeded();
}

void Player::toString() {
	cout << "Player name: " << name << "\nPlayer color: " << color
		<< "\nNumber of Power Plants owned: " << powerPlants.size() << endl;
	for (int i = 0; i < powerPlants.size(); i++) {
		powerPlants[i]->toString();
	}
	cout << "\nAmount of Elektro: " << endl;
	wallet.toString();
	cout << "\nNumber of Cities owned: " << citiesOwned.size() << "\nCity names: " << endl;
	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << citiesOwned[i].getCityName() << endl;
	}
}

void Player::removePowerPlant(PowerPlant* powerPlant) {
    removePowerPlant( powerPlant->getCardNumber() );
}

void Player::removePowerPlant(int powerPlantCardNumber) {
    for(int i = 0; i < this->powerPlants.size(); i++) {
        if( this->powerPlants.at(i)->getCardNumber() == powerPlantCardNumber ) {
            delete this->powerPlants.at(i);
            this->powerPlants.erase( this->powerPlants.begin()+i );
        }
    }
}

int Player::getCurrentTotalMaximumCityPoweringPotential() const {
    
    int currentTotalMaximumCityPoweringPotential = 0;
    for(int i = 0; i < this->powerPlants.size(); i++) {
        currentTotalMaximumCityPoweringPotential += powerPlants.at(i)->getCitiesPowered();
    }
    
    return currentTotalMaximumCityPoweringPotential;
}
