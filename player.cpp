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
}

Player::Player(string name, string color) {
	this->name = name;
	this->color = color;
	wallet = Elektro(10, 4, 0);
}

Player::~Player() {
	for (int i=0; i < citiesOwned.size(); i++){
		delete citiesOwned[i];
		citiesOwned[i] = NULL;
	}
}

string Player::getName() {
	return name;
}

string Player::getColor() {
	return color;
}

vector<PowerPlant> Player::getPowerPlant() {
	return powerPlants;
}


vector<ResourceToken> Player::getResources() {
	return resources;
}

void Player::addCity(City * city) {
	citiesOwned.push_back(city);
}

void Player::addPowerPlant(PowerPlant p) {
	powerPlants.push_back(p);
}

vector<City*> Player::getCitiesOwned() {
	return citiesOwned;
}

void  Player::collectElektro(int _bill1, int _bill10, int _bill50)
{
	wallet.addElektros(_bill1, _bill10, _bill50);
}

void Player::spendElektros(int _bill1, int _bill10, int _bill50)
{
	wallet.spendElektros(_bill1, _bill10, _bill50);
}

void  Player::getWallet()
{
	wallet.toString();
}

int  Player::getTotalWallet()
{
	return wallet.getTotalBalance();
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

	cout << "\nAmount of Elektro: " << endl;
	wallet.toString();
	cout << "\nNumber of Cities owned: " << citiesOwned.size() << "\nCity names: " << endl;
	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << citiesOwned.at(i)->getCityName() << endl;
	}
}

/*//
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
}

Player::Player(string name, string color){
this-> name = name;
this-> color = color;
}

Player::~Player(){
}

string Player::getName() {
return name;
}

string Player::getColor() {
return color;
}

vector<PowerPlant> Player::getPowerPlants(){
return powerPlants;
}

//returns wallet not just one Elektro object
vector<ElektroBill> Player::getElektros(){
return elektros;
}

vector<RessourceToken> Player::getResources(){
return resources;
}

void Player::addCity(City city) {
citiesOwned.push_back(city);
}

void Player::addPowerPlant(PowerPlant p) {
powerPlants.push_back(p);
}

void Player::collectElektro(ElektroBill e) {
elektros.push_back(e);
}

//void Player::removeElektro(int quantity, int billValue) {
//elektros.push_back(Elektro(quantity, billValue));
//elektros.erase
//}

void Player::toString(){
cout << "Player name: " << name << "\nPlayer color: " << color
<< "\nNumber of Power Plants owned: " << powerPlants.size() << endl;
int sum = 0;
for (int j = 0; j < elektros.size(); j++){
sum += elektros[j].getBalance();
}
cout << "\nAmount of Elektro: " << sum
<< "\nNumber of Cities owned: " << citiesOwned.size() << "\nCity names: " << endl;
for (int i = 0; i < citiesOwned.size(); i++) {
cout << citiesOwned[i].getCityName() << endl;
}
}
*/
