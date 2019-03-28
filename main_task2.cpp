//  main.cpp
//  player
//  Driver class for Player object
//

#include <iostream>
#include <algorithm>
#include <random>
#include <ctype.h>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "Market.hpp"
#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;

static void makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket)
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

static void deleteDeck(vector<GameCard*> &_deck) {
	for (int i = 0; i < _deck.size(); i++) {

		delete _deck[i];
		_deck[i] = NULL;
	}
}

static void sortMarket(vector<GameCard*> &_powerPlantMarket)
{
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}

static GameCard* drawCard(vector<GameCard*> &deck) {
	GameCard *temp = deck.at(0);
	deck.erase(deck.begin());
	return temp;
}

static void DeterminePlayerOrder(vector<Player*> &players, int round) {

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
		}

		//sort the order of the vertex
		std::sort(players.begin(), players.end(), Player::compByOrder);
		for (int i = 0; i < players.size(); i++) {
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

// Returns true if s is a number else false 
static bool isNumber(string s) {
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

//PASS !!!
static void Pass(Player * pl) {
	cout << "No powerplant interests " << pl->getName() << "." << endl;
	cout << endl;
}

//AUCTION!!!!!
static string Auction(PowerPlant * &powerplant, vector<Player*> &players, Player * pl) {
	cout << endl;
	cout << "$$$$$$ Give your best price! $$$$$$" << endl;
	cout << endl;

	//attributes
	vector<Player*> player = players; //call copy constructor
	int price = powerplant->getCardNumber();
	int newprice = price;
	char input;
	bool firstBid = true;
	bool lastBid = true;

	//resize the players that are allowed to enter the auction
	for (int i = 0; i < pl->getplayerOrder(); i++) {
		player.erase(player.begin());
	}

	//enter the Auctioning loop
	while (player.size() > 1) {
		for (int i = 0; i < player.size(); i++) {
			if (player.size() == 1 && lastBid) {
				break;
			}
			else {
				cout << player[i]->getName() << ", would you like to Pass or Bid on this powerplant?";
				powerplant->toString();
				cout << endl;
				cout << "Pass or Bid? (P/B). Current bid is " << price << " Elektros: ";
				cin >> input;

				//make sure user inputs correct thing
				while (input != 'P' && input != 'B') {
					cout << "This input is not valid. Please type in P (for Pass) or B (for Bid): ";
					cin >> input;
				}

				if (input == 'P') {
					cout << endl;
					cout << "Looks like this powerplant is not worth it for " << player[i]->getName() << endl;
					cout << endl;
					player.erase(player.begin() + i);
					if (player.size() == 0) { //manages possibility that everyone passes
						break;
					}
					else {
						//handles the bug that when everybody passes, the last player automatically wins the bid (bad)
						if (player[0]->getName() == players[players.size()-1]->getName()) { 
							i -= 1;
							lastBid = false;
						}
						else
							i -= 1;
					}
				}

				if (input == 'B') {
					if (firstBid) { //The first bid should be the same price as the card number
						cout << "How much would you like to bid? (minimum " << price << " Elektros): ";
						cin >> newprice;
						while (newprice < price) {
							cout << "What are you doing? The minimum bid is " << price << " Elektros! Try again: ";
							cin >> newprice;
						}
						firstBid = false;
					}
					else { //The other bids should be bigger than the previous bidding price
						cout << "How much would you like to bid? (minimum " << price + 1 << " Elektros): ";
						cin >> newprice;
						while (newprice <= price) {
							cout << "What are you doing? The minimum bid is " << price + 1 << " Elektros! Try again: ";
							cin >> newprice;
						}
					}
					price = newprice; //update price

					cout << player[i]->getName() << " has chosen to Bid " << price << " Elektros for this powerplant." << endl;
					cout << endl;
				}
			}
		}
	}

	if (player.size() == 1) { //Manage the possibility that every one passes
		cout << "*******" << player[0]->getName() << " won the Bid with " << price << " Elektros!*******" << endl;
		cout << endl;

		//do payment
		//calculate the amount of bills needed
		int bill1 = 0;
		int bill10 = 0;
		int bill50 = 0;

		bill50 = (price - price % 50) / 50;
		price -= bill50 * 50;
		bill10 = (price - price % 10) / 10;
		price -= bill10 * 10;
		bill1 = price;

		//print before after wallet and spend electros
		for (int k = 0; k < players.size(); k++) {
			if (player[0]->getName() == players[k]->getName()) {
				cout << "Your previous balance: " << endl;
				players[k]->walletToString();
				players[k]->spendElektros(bill1, bill10, bill50); //update wallet
				cout << "Your new balance: " << endl;
				players[k]->walletToString();
				players[k]->addPowerPlant(*powerplant); //update owned powerplants
			}
		}

		string pause;
		cout << "Enter anything to continue..." << endl;
		cin >> pause;
		//remove powerplant from vector
		return powerplant->getIdentifier();
	}
	else if (player.size() == 0){ //Manage the possibility that every one passes
		string pause;
		cout << "... No one bid? Why did you guys enter the auction in the first place? Oh well..." << endl;
		cout << "Enter anything to continue..." << endl;
		cin >> pause;
		return "";
	}
}

//PHASE 2!
static vector<GameCard*> EnterAuctioningPhase(vector<GameCard*> &ppMarket, vector<Player*> &players) {
	vector<PowerPlant*> powerPlantMarket; //copy 
	for (int i = 0; i < ppMarket.size(); i++) {
		powerPlantMarket.push_back(static_cast<PowerPlant*>(ppMarket[i]));
	}

	//task 2 - phase 2
	string removePP;
	string input;

	for (int i = 0; i < players.size(); i++) {
		for (int j = 0; j < powerPlantMarket.size(); j++) {
			powerPlantMarket[j]->toString();
		}
		cout << endl;
		cout << players[i]->getName() << ", would you like to Pass or Auction a powerplant?" << endl;
		cout << endl;
		cout << "If you would like to Pass, press 'P'. If you would like to Auction a powerplant, enter the card number of the powerplant you want: ";
		cin >> input;
		cout << endl;

		//find if card is available
		bool isCardInVector = false;
		int targetpp;
		if (isNumber(input)) { //check if input is a number
			for (int k = 0; k < powerPlantMarket.size(); k++) { //check if powerplant number is available
				if (std::stoi(input) == powerPlantMarket[k]->getCardNumber()) {
					targetpp = k;
					isCardInVector = true;
					break;
				}
				else
					isCardInVector = false;
			}
		}

		//manage user inputting invalid stuff
		while (input != "P" && isCardInVector == false) {
			cout << "This input is not valid. Please type in P (for Pass) or powerplant card number: ";
			cin >> input;
			cout << endl;
			if (isNumber(input)) { //check if input is a number
				for (int k = 0; k <= powerPlantMarket.size(); k++) { //check if powerplant number is available
					if (std::stoi(input) == powerPlantMarket[k]->getCardNumber()) {
						targetpp = k;
						isCardInVector = true;
						break;
					}
					else
						isCardInVector = false;
				}
			}
		}
		if (input == "P") {
			//PLAYER PASSES... nothing much happens
			Pass(players[i]);
		}
		if (isCardInVector) {
			cout << players[i]->getName() << " has chosen to Auction (A) for powerplant: " << powerPlantMarket[targetpp]->getCardNumber() << endl;
			//ENTER AUCTION!!!!
			removePP = Auction(powerPlantMarket[targetpp], players, players[i]);
			cout << endl;

			//remove the bought powerplant from the market
			for (int m = 0; m < powerPlantMarket.size(); m++) {
				if (removePP == powerPlantMarket[m]->getIdentifier()) {
					powerPlantMarket.erase(powerPlantMarket.begin() + m);
				}
			}
			for (int m = 0; m < ppMarket.size(); m++) {
				if (removePP == ppMarket[m]->getIdentifier()) {
					ppMarket.erase(ppMarket.begin() + m);
				}
			}
		}
	}
	//display the posessions of each player
	for (int i = 0; i < players.size(); i++) {
		players[i]->toString();
		cout << endl;
	}

	return ppMarket;
}

int main() {
	
	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "germany.map");
	
	//============================== Assignment 2, task 2, ================================================
	static vector<GameCard*> deck;
	static vector<GameCard*> powerPlantMarket;



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


	static vector<Player*> players;
	
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
	bool gameIsNotFinished = false;
	int round = 1;
	string pause;

	while (gameIsNotFinished == false){
		
		while (round >= 1) {
			
			//task 2 - phase 1
			DeterminePlayerOrder(players, round);

			round += 1;
			DeterminePlayerOrder(players, round);

			cout << "Enter anything to continue..." << endl;
			cin >> pause;

			//task 2 - phase 2
			EnterAuctioningPhase(powerPlantMarket, players); 

			cout << "Enter anything to continue..." << endl;
			cin >> pause;

			round = 0;
		}
		gameIsNotFinished = true;
	}
	deleteDeck(deck);


	//delete memory
	for (int i = 0; i < players.size(); i++) {
		delete players[i];
		players[i] = NULL;
	}
	
	return 0;
}