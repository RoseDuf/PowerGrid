//  main.cpp
//  player
//  Driver class for Player object
//
/*
#include <iostream>
#include <algorithm>
#include <random>
#include <ctype.h>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"
#include "Elektro.hpp"
#include "Market.hpp"
#include "Game.h"
#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;

static void shuffle(vector<GameCard*> &_deck) {
	random_shuffle(_deck.begin(), _deck.end());
}

static void makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket)
{

	//  PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed);

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
	shuffle(_deck);
	//random_shuffle(_deck.begin(),_deck.end());
	_deck.push_back(s3);
	_deck.insert(_deck.begin(), p11);
}

static void print(vector<GameCard*> &_deck)
{
	for (int i = 0; i < _deck.size(); i++)
	{
		_deck[i]->toString();
	}
}

static void deleteDeck(vector<GameCard*> &_deck)
{
	for (int i = 0; i < _deck.size(); i++)
	{

		delete _deck[i];
		_deck[i] = NULL;
	}

}

static void sortMarket(vector<GameCard*> &_powerPlantMarket)
{
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}
static int checkProfit(int _num)
{
	if (_num == 0) return 10;
	else if (_num == 1) return 22;
	else if (_num == 2) return 33;
	else if (_num == 3) return 44;
	else if (_num == 4) return 54;
	else if (_num == 5) return 64;
	else if (_num == 6) return 73;
	else if (_num == 7) return 82;
	else if (_num == 8) return 90;
	else if (_num == 9) return 98;
	else if (_num == 10) return 105;
	else if (_num == 11) return 112;
	else if (_num == 12) return 118;
	else if (_num == 13) return 124;
	else if (_num == 14) return 129;
	else if (_num == 15) return 134;
	else if (_num == 16) return 138;
	else if (_num == 17) return 142;
	else if (_num == 18) return 145;
	else if (_num == 19) return 148;
	else if (_num == 20) return 150;
	return 0;
}

static void DeterminePlayerOrder(vector<Player*> &players, int phase) {

	vector<int> playerOrder;

	if (phase == 1) {
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
						if (player[0]->getName() == players[players.size() - 1]->getName()) {
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
				players[k]->addPowerPlant(powerplant); //update owned powerplants
			}
		}

		string pause;
		cout << "Enter anything to continue..." << endl;
		cin >> pause;
		//remove powerplant from vector
		return powerplant->getIdentifier();
	}
	else if (player.size() == 0) { //Manage the possibility that every one passes
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

	//============================== Assignment 2, task 1, ================================================
	// Select the number of players in the game
	std::cout << "How many players? (2-6):";
	int amountOfPlayers = 0;
	string playerName = "";
	string color = "";
	string aiorhuman = "";
	bool AI = false;

	vector<string> colors;
		colors.push_back("Red");
		colors.push_back("Blue");
		colors.push_back("Black");
		colors.push_back("Purple");
		colors.push_back("Green");
		int colorsSize = colors.size();

	static vector<Player*> players;

	std::cin >> amountOfPlayers;

	int amountOfRegionsToChoose = 0;

	cout << "Humans or AI? (type in either Humans or AI)" << endl;
	cin >> aiorhuman;
	while (aiorhuman != "AI" && aiorhuman != "Humans") {
		cout << "We asked for Humans or AI... (type in either Humans or AI)" << endl;
		cin >> aiorhuman;
	}
	if (aiorhuman == "AI") {
		AI = true;
	}
	else if (aiorhuman == "Humans") {
		AI = false;
	}

	if (amountOfPlayers == 2) {
		amountOfRegionsToChoose = 3;
		if (AI == true) {
			players.push_back(new Player("Nicole", "Red"));
			players.push_back(new Player("Voldermort", "Green"));
		}
		else {
			for (int i = 0; i < 2; i++) {
				cout << "Enter your name: ";
				cin >> playerName;
				cout << "Enter your color choice: ";
				cin >> color;
				for (int j = 0; j < colors.size(); j++) {
					if (color == colors[j]) {
						colors.erase(colors.begin() + j);
					}
				}
				while (colorsSize == colors.size()) {
					cout << "Enter another color choice: ";
					cin >> color;
					for (int j = 0; j < colors.size(); j++) {
						if (color == colors[j]) {
							colors.erase(colors.begin() + j);
						}
					}
				}
				players.push_back(new Player(playerName, color));
				colorsSize = colors.size();
			}
		}
	}
	else if (amountOfPlayers == 3) {
		amountOfRegionsToChoose = 3;
		if (AI == true) {
			players.push_back(new Player("Nicole", "Red"));
			players.push_back(new Player("Voldermort", "Green"));
			players.push_back(new Player("Pikachu", "Blue"));
		}
		else {
			for (int i = 0; i < 3; i++) {
				cout << "Enter your name: ";
				cin >> playerName;
				cout << "Enter your color choice: ";
				cin >> color;
				for (int j = 0; j < colors.size(); j++) {
					if (color == colors[j]) {
						colors.erase(colors.begin() + j);
					}
				}
				while (colorsSize == colors.size()) {
					cout << "Enter another color choice: ";
					cin >> color;
					for (int j = 0; j < colors.size(); j++) {
						if (color == colors[j]) {
							colors.erase(colors.begin() + j);
						}
					}
				}
				players.push_back(new Player(playerName, color));
				colorsSize = colors.size();
			}
		}
	}
	else if (amountOfPlayers == 4) {
		amountOfRegionsToChoose = 4;
		if (AI == true) {
			players.push_back(new Player("Nicole", "Red"));
			players.push_back(new Player("Voldermort", "Green"));
			players.push_back(new Player("Pikachu", "Blue"));
			players.push_back(new Player("Smith", "Purple"));
		}
		else {
			for (int i = 0; i < 4; i++) {
				cout << "Enter your name: ";
				cin >> playerName;
				cout << "Enter your color choice: ";
				cin >> color;
				for (int j = 0; j < colors.size(); j++) {
					if (color == colors[j]) {
						colors.erase(colors.begin() + j);
					}
				}
				while (colorsSize == colors.size()) {
					cout << "Enter another color choice: ";
					cin >> color;
					for (int j = 0; j < colors.size(); j++) {
						if (color == colors[j]) {
							colors.erase(colors.begin() + j);
						}
					}
				}
				players.push_back(new Player(playerName, color));
				colorsSize = colors.size();
			}
		}
	}
	else if (amountOfPlayers == 5) {
		amountOfRegionsToChoose = 5;
		if (AI == true) {
			players.push_back(new Player("Nicole", "Red"));
			players.push_back(new Player("Voldermort", "Green"));
			players.push_back(new Player("Pikachu", "Blue"));
			players.push_back(new Player("Smith", "Purple"));
			players.push_back(new Player("Roger", "Black"));
		}
		else {
			for (int i = 0; i < 5; i++) {
				cout << "Enter your name: ";
				cin >> playerName;
				cout << "Enter your color choice: ";
				cin >> color;
				for (int j = 0; j < colors.size(); j++) {
					if (color == colors[j]) {
						colors.erase(colors.begin() + j);
					}
				}
				while (colorsSize == colors.size()) {
					cout << "Enter another color choice: ";
					cin >> color;
					for (int j = 0; j < colors.size(); j++) {
						if (color == colors[j]) {
							colors.erase(colors.begin() + j);
						}
					}
				}
				players.push_back(new Player(playerName, color));
				colorsSize = colors.size();
			}
		}
	}
	else if (amountOfPlayers == 6) {
		amountOfRegionsToChoose = 5;
		if (AI == true) {
			players.push_back(new Player("Nicole", "Red"));
			players.push_back(new Player("Voldermort", "Green"));
			players.push_back(new Player("Pikachu", "Blue"));
			players.push_back(new Player("Smith", "Purple"));
			players.push_back(new Player("Roger", "Black"));
			players.push_back(new Player("Dustyn", "Yellow"));
		}
		else {
			for (int i = 0; i < 6; i++) {
				cout << "Enter your name: ";
				cin >> playerName;
				cout << "Enter your color choice: ";
				cin >> color;
				for (int j = 0; j < colors.size(); j++) {
					if (color == colors[j]) {
						colors.erase(colors.begin() + j);
					}
				}
				while (colorsSize == colors.size()) {
					cout << "Enter another color choice: ";
					cin >> color;
					for (int j = 0; j < colors.size(); j++) {
						if (color == colors[j]) {
							colors.erase(colors.begin() + j);
						}
					}
				}
				players.push_back(new Player(playerName, color));
				colorsSize = colors.size();
			}
		}
	}

	std::cout << "true = " << true << std::endl; // just to emphasize that true = 1

												 // Select a map
	std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
	std::cout << "1) Germany map" << std::endl;
	std::cout << "2) USA map" << std::endl;
	std::cout << "3) An invalid map with (a) duplicate edge(s)" << std::endl;
	std::cout << "4) An invalid map with (a) missing edge(s)" << std::endl;

	int mapChoice;

	std::cin >> mapChoice;

	std::string mapFilename;
	if (mapChoice == 1) {
		mapFilename = "germany.map";
	}
	else if (mapChoice == 2) {
		mapFilename = "usa.map"; // TODO
	}
	else if (mapChoice == 3) {
		mapFilename = "duplicate_edge(s).map";
	}
	else if (mapChoice == 4) {
		mapFilename = "missing_edge(s).map";
	}
	//else {
	// throw no map exception or something like that
	//}

	MapData mapData = PowerGridIO::getMapData(mapFilename);
	std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
	vector<string> chosenRegCols;

	if (AI == true) {
		//powerGridAI.executeRegionColorChoice(std::vector<std::string> alreadyChosenColors) or something like that
	}
	else {
		for (int i = 0; i < amountOfRegionsToChoose; i++) {

			std::cout << "Choose region color " << (i + 1) << ":";
			std::string currentRegionColorChoice = "";
			std::cin >> currentRegionColorChoice;
			chosenRegCols.push_back(currentRegionColorChoice);
		}
	}
	int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
	GraphBuilder graph = GraphBuilder(amountOfVertices, mapFilename);

	std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
	std::cout << std::endl;
	std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;

	std::cout << std::endl;

	while (graph.hasDuplicateEdge() || graph.hasMissingEdge()) {
		std::cout << "ERROR: The map is invalid." << std::endl;
		cout << endl;
		std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
		std::cout << "1) Germany map" << std::endl;
		std::cout << "2) USA map" << std::endl;
		std::cout << "3) An invalid map with (a) duplicate edge(s)" << std::endl;
		std::cout << "4) An invalid map with (a) missing edge(s)" << std::endl;

		int mapChoice;

		std::cin >> mapChoice;

		std::string mapFilename;
		if (mapChoice == 1) {
			mapFilename = "germany.map";
		}
		else if (mapChoice == 2) {
			mapFilename = "usa.map"; // TODO
		}
		else if (mapChoice == 3) {
			mapFilename = "duplicate_edge(s).map";
		}
		else if (mapChoice == 4) {
			mapFilename = "missing_edge(s).map";
		}
		//else {
		// throw no map exception or something like that
		//}

		MapData mapData = PowerGridIO::getMapData(mapFilename);
		std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
		vector<string> chosenRegCols;

		for (int i = 0; i < amountOfRegionsToChoose; i++) {

			std::cout << "Choose region color " << (i + 1) << ":";
			std::string currentRegionColorChoice = "";
			std::cin >> currentRegionColorChoice;
			chosenRegCols.push_back(currentRegionColorChoice);
		}

		int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
		graph = GraphBuilder(amountOfVertices, mapFilename);

		std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
		std::cout << std::endl;
		std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have duplicate edge(s)?:" << graph.hasDuplicateEdge() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have missing edge(s)?:" << graph.hasMissingEdge() << std::endl;

		std::cout << std::endl;
	}
	
	std::cout << "The map is valid." << std::endl;

	//============================== Assignment 2, task 2, ================================================
	string pause;
	static vector<GameCard*> deck;
	static vector<GameCard*> powerPlantMarket;

	Market market = Market();

	Game g1 = Game();

	makingDeck(deck, powerPlantMarket);
	sortMarket(powerPlantMarket);
	cout << "Enter anything to continue..." << endl;
	cin >> pause;

	//Game loop !!!!
	bool gameIsFinished = false;
	int phase = 1;
	static int step = 1; //should be step
	
	cout << "/////////////////////////////////////////////////////////////////////////" << endl;
//START OF GAME LOOP !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << "GAME HAS STARTED" << endl;
	while (gameIsFinished == false) {

		while (phase >= 1) {

			//step 1
			DeterminePlayerOrder(players, phase);

			cout << "Enter anything to continue..." << endl;
			cin >> pause;

			//step 2
			EnterAuctioningPhase(powerPlantMarket, players);

			cout << "Enter anything to continue..." << endl;
			cin >> pause;

			//step 3
			



			phase += 1;

			for (int i = 0; i < players.size(); i++) {
				if (players[i]->getCitiesOwned().size() == 17)
					phase = 0; // end of game
				//GOTTA HANDLE WINNING CONDITIONS!
			}
		}
		gameIsFinished = true;
	} //END OF GAME LOOP !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


	deleteDeck(deck);


	//delete memory
	for (int i = 0; i < players.size(); i++) {
		delete players[i];
		players[i] = NULL;
	}

	return 0;
}

*/