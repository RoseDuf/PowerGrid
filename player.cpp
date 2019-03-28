//
//  player.cpp
//  player
//

#include <iostream>
#include <vector>
#include "player.hpp"
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
}

Player::Player(string name, string color, vector<PowerPlant>
	powerPlant, Elektro wallet, vector<City> cities,
	/*vector<ResourceToken> resources,*/ int playerOrder) {
	this->name = name;
	this->color = color;
	this->wallet = wallet;
	this->citiesOwned = cities;
	//this->resources = resources;
	this->playerOrder = playerOrder;
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

string Player::getName() {
	return name;
}
void Player::setName(string n) {
	name = n;
}

string Player::getColor() {
	return color;
}
void Player::setColor(string c) {
	color = c;
}

vector<PowerPlant> Player::getPowerPlant() {
	return powerPlants;
}
void Player::setPowerPlant(vector<PowerPlant> pp) {
	powerPlants = pp;
}
void Player::addPowerPlant(PowerPlant p) {
	powerPlants.push_back(p);
}

//vector<ResourceToken> Player::getResources() {
//	return resources;
//}

vector<City> Player::getCitiesOwned() {
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
int  Player::getTotalWallet() {
	return wallet.getTotalBalance();
}
void Player::setTotalWallet(Elektro w) {
	wallet = w;
}

int Player::getplayerOrder() {
	return playerOrder;
}
void Player::setplayerOrder(int t) {
	playerOrder = t;
}

//void Player::removeElektro(int quantity, int billValue) {
//elektros.push_back(Elektro(quantity, billValue));
//elektros.erase
//}

void Player::toString() {
	cout << "Player name: " << name << "\nPlayer color: " << color
		<< "\nNumber of Power Plants owned: " << powerPlants.size() << endl;
	for (int i = 0; i < powerPlants.size(); i++) {
		powerPlants[i].toString();
	}
	cout << "\nAmount of Elektro: " << endl;
	wallet.toString();
	cout << "\nNumber of Cities owned: " << citiesOwned.size() << "\nCity names: " << endl;
	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << citiesOwned[i].getCityName() << endl;
	}
}

//void Player::Pass(PowerPlant p) {
//	cout << name << " has chosen to Pass (P) on powerplant " << p.getCardNumber << endl;
//	cout << endl;
//}

//void Player::Auction(GameCard * p) {
//
//}
