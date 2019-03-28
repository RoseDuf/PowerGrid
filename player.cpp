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
	playerColor = "BLANK";
}

Player::Player(string name, string playerColor) {
	this->name = name;
	this->playerColor = playerColor;
	wallet = Elektro(10, 4, 0);
}

Player::~Player() {
}

//void Player::powerCity(City city, PowerPlant powerplant, string type, Market market*)
//{
 //   city.setPoweredState(true);
  //  powerplant.powerCity(type, &market);
//}

void Player::powerCity(City city, PowerPlant powerplant, string type)
{
    city.setPoweredState(true);
    powerplant.powerCity(type);
}

int Player::getCitiesPowered()
{
    int temp = 0;
    for(int i = 0 ; i < citiesOwned.size(); i++)
    {
        if(citiesOwned[i].getPoweredState()) temp++;
    }
    return temp;
}
//setting powered back to false as we are starting another round in the game
void Player::setCitiesPowered()
{
    for(int i = 0 ; i < citiesOwned.size(); i++)
    {
        citiesOwned[i].setPoweredState(false);
    }
}


int  Player::getTotalCoal()
{
    int temp = 0;
    for(int i = 0; i < powerPlants.size() ; i++)
    {
        temp+=powerPlants[i].getRTStocked("coal");
    }
    return temp;
}

int  Player::getTotalOil()
{
    int temp = 0;
    for(int i = 0; i < powerPlants.size() ; i++)
    {
        temp+=powerPlants[i].getRTStocked("oil");
    }
    return temp;
}

int  Player::getTotalGarbage()
{
    int temp = 0;
    for(int i = 0; i < powerPlants.size() ; i++)
    {
        temp+=powerPlants[i].getRTStocked("garbage");
    }
    return temp;
}

int  Player::getTotalUranium()
{
    int temp = 0;
    for(int i = 0; i < powerPlants.size() ; i++)
    {
        temp+=powerPlants[i].getRTStocked("uranium");
    }
    return temp;
}

string Player::getName() {
	return name;
}

string Player::getColor() {
	return playerColor;
}

vector<PowerPlant> Player::getPowerPlant() {
	return powerPlants;
}
/*

vector<ResourceToken> Player::getResources() {
	return resources;
}
 */

//CITIES ARENT GETTING ADDED TO PLAYER?!
void Player::addCity(City city) {
	cout << "hiiiiiiiiii" << endl;
	citiesOwned.push_back(city);
    numCitiesOwned++;
	cout << citiesOwned.size() << endl;
}

void Player::addPowerPlant(PowerPlant p) {
  
    
	powerPlants.push_back(p);
}

int Player::getNumCitiesOwned()
{
    return numCitiesOwned;
}

int Player::getNumPPOwned()
{
    return numPPOwned;
}
vector<City> Player::getCitiesOwned() {
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


//void Player::removeElektro(int quantity, int billValue) {
//elektros.push_back(Elektro(quantity, billValue));
//elektros.erase
//}

void Player::toString() {


	cout << "Player name: " << name << "\nPlayer color: " << playerColor
    << "\nNumber of Power Plants owned: " << powerPlants.size() << "\nCity names: " << endl;
    for (int i = 0; i < powerPlants.size(); i++) {
        //pointer problem to fix with roses solution
        //cout << powerPlants[i].toString() << endl;
    }

	cout << "\nAmount of Elektro: " << endl;
	wallet.toString();
	cout << "\nNumber of Cities owned: " << citiesOwned.size() << "\nCity names: " << endl;
	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << citiesOwned[i].getCityName() << endl;
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
