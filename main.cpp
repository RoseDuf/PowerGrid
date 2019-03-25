//  main.cpp
//  player
//  Driver class for Player object
//
/*
#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;


int main() {
    GameState gameState = GameStateIO::readXmlFile("powergrid_cities.map");
    std::vector<City> cities = gameState.getCities();
    std::vector<EdgeTriplet> edgeTriplets = gameState.getEdgeTriplets();
    std::cout << "hilo" << std::endl;

	for (int i = 0; i < cities.size(); i++) {
		std::cout << cities[i].getCityNumber() << endl;
	}

	
	for (int i = 0; i < edgeTriplets.size(); i++) {
		std::cout << std::get<0>(edgeTriplets[i]).getCityNumber() << endl;
	}

	

}
*/

//  main.cpp
//  player
//  Driver class for Player object
//

#include <iostream>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "Market.hpp"
//#include "ResourceToken.hpp"
#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;

static void makingDeck(vector<GameCard*> &_deck, vector<PowerPlant*> &_powerPlantMarket)
{
	PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
	PowerPlant *p2 = new PowerPlant(4, 1, 2, 0, 0, 0);
	PowerPlant *p3 = new PowerPlant(5, 1, 2, 2, 0, 0);
	PowerPlant *p4 = new PowerPlant(6, 1, 0, 0, 1, 0);
	PowerPlant *p5 = new PowerPlant(7, 2, 0, 3, 0, 0);
	PowerPlant *p6 = new PowerPlant(8, 2, 3, 0, 0, 0);
	PowerPlant *p7 = new PowerPlant(9, 1, 0, 1, 0, 0);
	PowerPlant *p8 = new PowerPlant(10, 2, 2, 0, 0, 0);
	PowerPlant *p9 = new PowerPlant(11, 2, 0, 0, 0, 1);
	PowerPlant *p10 = new PowerPlant(12, 2, 2, 2, 0, 0);
	PowerPlant *p11 = new PowerPlant(13, 1, 0, 0, 0, 0);
	PowerPlant *p12 = new PowerPlant(14, 2, 0, 0, 2, 0);
	PowerPlant *p13 = new PowerPlant(15, 3, 2, 0, 0, 0);
	PowerPlant *p14 = new PowerPlant(16, 3, 0, 2, 0, 0);
	PowerPlant *p15 = new PowerPlant(17, 2, 0, 0, 0, 1);
	PowerPlant *p16 = new PowerPlant(18, 2, 0, 0, 0, 0);
	PowerPlant *p17 = new PowerPlant(19, 3, 0, 0, 2, 0);
	PowerPlant *p18 = new PowerPlant(20, 5, 3, 0, 0, 0);
	PowerPlant *p19 = new PowerPlant(21, 4, 2, 2, 0, 0);
	PowerPlant *p20 = new PowerPlant(22, 2, 0, 0, 0, 0);
	PowerPlant *p21 = new PowerPlant(23, 3, 0, 0, 0, 1);
	PowerPlant *p22 = new PowerPlant(24, 4, 0, 0, 2, 0);
	PowerPlant *p23 = new PowerPlant(25, 5, 2, 0, 0, 0);
	PowerPlant *p24 = new PowerPlant(26, 5, 0, 2, 0, 0);
	PowerPlant *p25 = new PowerPlant(27, 3, 0, 0, 0, 0);
	PowerPlant *p26 = new PowerPlant(28, 4, 0, 0, 0, 1);
	PowerPlant *p27 = new PowerPlant(29, 4, 2, 2, 0, 0);
	PowerPlant *p28 = new PowerPlant(30, 6, 0, 0, 3, 0);
	PowerPlant *p29 = new PowerPlant(31, 6, 3, 0, 0, 0);
	PowerPlant *p30 = new PowerPlant(32, 6, 0, 3, 0, 0);
	PowerPlant *p31 = new PowerPlant(33, 4, 0, 0, 0, 0);
	PowerPlant *p32 = new PowerPlant(34, 5, 0, 0, 0, 1);
	PowerPlant *p33 = new PowerPlant(35, 5, 0, 1, 0, 0);
	PowerPlant *p34 = new PowerPlant(36, 7, 3, 0, 0, 0);
	PowerPlant *p35 = new PowerPlant(37, 4, 0, 0, 0, 0);
	PowerPlant *p36 = new PowerPlant(38, 7, 0, 0, 3, 0);
	PowerPlant *p37 = new PowerPlant(39, 6, 0, 0, 0, 1);
	PowerPlant *p38 = new PowerPlant(40, 6, 0, 2, 0, 0);
	PowerPlant *p39 = new PowerPlant(42, 6, 2, 0, 0, 0);
	PowerPlant *p40 = new PowerPlant(44, 5, 0, 0, 0, 0);
	PowerPlant *p41 = new PowerPlant(46, 7, 3, 3, 0, 0);
	PowerPlant *p42 = new PowerPlant(50, 6, 0, 0, 0, 0);


	GameCard *s3 = new GameCard("s3");


	//SETTING UP THE POWERPLANT MARKET
	_powerPlantMarket.push_back(p1);
	_powerPlantMarket.push_back(p2);
	_powerPlantMarket.push_back(p3);
	_powerPlantMarket.push_back(p4);
	_powerPlantMarket.push_back(p5);
	_powerPlantMarket.push_back(p6);
	_powerPlantMarket.push_back(p7);


	//making the rest of the deck, ready to shuffle
	_deck.push_back(p9);
	_deck.push_back(p10);
	//_deck.push_back(p11);
	_deck.push_back(p12);
	_deck.push_back(p13);
	_deck.push_back(p14);
	_deck.push_back(p15);
	_deck.push_back(p16);
	_deck.push_back(p17);
	_deck.push_back(p18);
	_deck.push_back(p19);
	_deck.push_back(p20);
	_deck.push_back(p21);
	_deck.push_back(p22);
	_deck.push_back(p23);
	_deck.push_back(p24);
	_deck.push_back(p25);
	_deck.push_back(p26);
	_deck.push_back(p27);
	_deck.push_back(p28);
	_deck.push_back(p29);
	_deck.push_back(p30);
	_deck.push_back(p31);
	_deck.push_back(p32);
	_deck.push_back(p33);
	_deck.push_back(p34);
	_deck.push_back(p35);
	_deck.push_back(p36);
	_deck.push_back(p37);
	_deck.push_back(p38);
	_deck.push_back(p39);
	_deck.push_back(p40);
	_deck.push_back(p41);
	_deck.push_back(p42);

	//following game rules:
	//top of deck: powerplant 13
	//bottom: step3 card
	random_shuffle(_deck.begin(), _deck.end());
	_deck.push_back(s3);
	_deck.insert(_deck.begin(), p11);
}

static void print(vector<GameCard*> &_deck){
	for (int i = 0; i < _deck.size(); i++)
	{
		_deck[i]->toString();
	}
}
static void print(vector<PowerPlant*> &_deck) {
	for (int i = 0; i < _deck.size(); i++)
	{
		_deck[i]->toString();
	}
}

static void deleteDeck(vector<GameCard*> &_deck) {
	for (int i = 0; i < _deck.size(); i++) {

		delete _deck[i];
		_deck[i] = NULL;
	}
}

static GameCard* drawCard(vector<GameCard*> &deck) {
	GameCard *temp = deck.at(0);
	deck.erase(deck.begin());
	return temp;
}

static void DeterminePlayerOrder(vector<Player*> players, int round) {

	vector<int> playerOrder;

	if (round == 1) {
		for (int i = 0; i < players.size(); i++) {
			playerOrder.push_back(i);
		}

		//give random turn to each player
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(playerOrder.begin(), playerOrder.end(), g);

		cout << "Initial player order: " << endl;
		cout << endl;

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(playerOrder[i]);
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}
		cout << endl;
	}

	else {
		cout << "Current player order: " << endl;
		cout << endl;

		//sort players by the number of cities they have (for the rest of the game)
		std::sort(players.begin(), players.end(), Player::compByCities);

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(i);
		}

		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}
		cout << endl;
	}
}

static void sortMarket(vector<PowerPlant*> &_powerPlantMarket)
{
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}

static void Auction(PowerPlant * powerplant, vector<Player*> players, Player * pl) {
	cout << "$$$$$$ Give your best price! $$$$$$" << endl;
	vector<Player*> player = players;
	bool bought = false;
	int price = powerplant->getCardNumber();
	int newprice = price;
	char input;

	for (int i = 0; i < pl->getplayerOrder(); i++) {
		player.erase(player.begin() + i);
	}

	while (player.size() != 1) {
		for (int i = 0; i < player.size(); i++) {
			cout << player[i]->getName() << ", would you like to Pass or Bid on this powerplant?";
			powerplant->toString();
			cout << endl;
			cout << "Pass or Bid? (P/B): ";
			cin >> input;
			cout << endl;
			while (input != 'P' && input != 'B') {
				cout << "This input is not valid. Please type in P (for Pass) or B (for Bid): ";
				cin >> input;
				cout << endl;
			}
			if (input == 'P') {
				player.erase(player.begin() + i);
				i -= 1;
			}
			if (input == 'B') {
				cout << "How much would you like to bid? (minimum " << price << " Elektros): ";
				cin >> newprice;
				while (newprice < price) {
					cout << "What are you doing? The minimum bid is " << price << " Elektros! Try again: ";
					cin >> newprice;
				}
				price = newprice;


				cout << players[i]->getName() << " has chosen to Bid " << price << " Elektros for this powerplant" << endl;
				cout << endl;
			}
		}
	}

	cout << player[0]->getName() << " won the Bid with " << price << " Elektros!" << endl;

	//TODO: Manage the possibility that every one passes

}


int main() {

//============================== Assignment 1 ================================================
	/*
	Elektro elektro = Elektro(10, 5, 50);
	//ResourceToken resource = ResourceToken(3, "oil");
	PowerPlant powerplant = PowerPlant(3, 2, 2, 0, 0, 0);
	City c1 = City(1, "Kiel", "GREEN");
	City c2 = City(2, "Hamburg", "GREEN");

	Player * p1 = new Player("Nicole", "Red");
	//p1.collectElektro(elektro);
	*/
	
	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "powergrid_cities.map");
	graph.buildMap();

	/*
	graph.printGraph();

	cout << endl;

	graph.removeRegions("ORANGE");

	graph.printGraph();

	cout << endl;
	
	//prints the contents of the 2D vector "connected" from GraphBuilder.h
	//vector<vector<int>> vec = graph.getConnected();
  
	//for (int i = 0; i < vec.size(); i++) {
	//	cout << "for slot " << i << " there is: " << endl;
	//	for (int j = 0; j < vec[i].size(); j++) {
	//		cout << vec[i][j] << endl;
	//	}
	//}

	//bool check1, check2, check3;
	//Test Cases
	//graph.CostFromOneCityToAnother(0, 1);
	//std::cout << std::boolalpha;
	graph.test_SizeOfMap_and_FileMap();
	//cout << check3 << endl;
	graph.test_Duplicate_Edges();
	//cout << check1 << endl;
	graph.test_MissingEdges();
	//cout << check2 << endl;

	cout << endl;

	//add tokens to map
	graph.add_ElektrosToCity(elektro, "Berlin");
	//graph.add_ResourcesToCity(resource, "Berlin");
	graph.add_PowerPlantToCity(powerplant, "Berlin");

	cout << endl;
	//print contents 
	graph.SearchCity("Berlin");

	cout << endl;

	
	//add player to city
	graph.add_CityToPlayer_and_PlayerToMap(p1, "Berlin");
	p1->addCity(c1);
	p1->addCity(c2);
	graph.AddPlayerToMap(p1);
	
	vector<City> citiesOwned = graph.FindCitiesOwnedByPlayer(p1);

	for (int i = 0; i < citiesOwned.size(); i++) {
		cout << "Player: " << p1->getName() << ", Color: " << p1->getColor()
			<< ", is in City: " << citiesOwned[i].getCityName() << endl;
	}

	cout << endl;

	//print contents
	graph.SearchCity("Berlin");
	graph.SearchCity("Kiel");
	graph.SearchCity("Hamburg");

	cout << endl;

	//print cities owned by player
	p1->toString();

	cin.get();
	
	*/
	
	//============================== Assignment 2, task 2, ================================================
	static vector<GameCard*> deck;
	static vector<PowerPlant*> powerPlantMarket;


	Market market = Market();

	makingDeck(deck, powerPlantMarket);
	//print(powerPlantMarket);
	//bureaucracy(deck, powerPlantMarket, market);
	//print(powerPlantMarket);
	sortMarket(powerPlantMarket);
	print(powerPlantMarket);
	// print(powerPlantMarket);
	//shuffle(deck);
	//print(deck);
	//cout << deck.size() << endl;


	vector<Player*> players;
	
	players.push_back(new Player("Nicole", "Red"));
	players.push_back(new Player("Voldermort", "Green"));
	players.push_back(new Player("Pikachu", "Blue"));
	players.push_back(new Player("Smith", "Purple"));

	graph.add_CityToPlayer_and_PlayerToMap(players[0], "Berlin");
	graph.add_CityToPlayer_and_PlayerToMap(players[0], "Frankfurt-O");
	graph.add_CityToPlayer_and_PlayerToMap(players[1], "Kiel");
	graph.add_CityToPlayer_and_PlayerToMap(players[2], "Frankfurt-M");
	graph.add_CityToPlayer_and_PlayerToMap(players[2], "Hamburg");
	graph.add_CityToPlayer_and_PlayerToMap(players[2], "Cuxhaven");


	//Game loop !!!!

	int numPlayers = players.size();
	vector<int> playerOrder;

	char input;

	bool gameIsNotFinished = false;
	int round = 1;

	while (gameIsNotFinished == false){
		
		while (round >= 1) {
			
			//task 2 - step 1
			DeterminePlayerOrder(players, round);
			std::sort(players.begin(), players.end(), Player::compByOrder);
			round += 1;
			DeterminePlayerOrder(players, round);
			std::sort(players.begin(), players.end(), Player::compByOrder);
			
			//task2 - step 2
			for (int i = 0; i < players.size(); i++) {
				for (int j = 0; j < powerPlantMarket.size(); j++) {
					cout << players[i]->getName() << ", would you like to Pass or Auction this powerplant?";
					powerPlantMarket[j]->toString();
					cout << endl;
					cout << "Pass or Auction? (P/A): ";
					cin >> input;
					cout << endl;
					while (input != 'P' && input != 'A') {
						cout << "This input is not valid. Please type in P (for Pass) or A (for Auction): ";
						cin >> input;
						cout << endl;
					}
					if (input == 'P') {
						//Player::Pass();
					}
					if (input == 'A') {
						cout << players[i]->getName() << " has chosen to Auction (A) for this powerplant" << endl;
						Auction(powerPlantMarket[j], players, players[i]);
						cout << endl;
						break;
					}
				}
			}

			round = 0;
		}
		gameIsNotFinished = true;
	}
	deleteDeck(deck);
	
	return 0;
}

