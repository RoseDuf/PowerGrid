//Game Play Driver for Phase 3 + 4
//GameState getTurnOfPlayer returns int

//#include "GameState.hpp"
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include "Market.hpp"

using namespace std;

Game::Game()
{

	cout << "Welcome to PowerGrid!" << endl;
	cout << endl;
	
}

//METHODS FOR DECK
void Game::print(vector<GameCard*> &_deck) {
	for (int i = 0; i < _deck.size(); i++)
	{
		_deck[i]->toString();
	}
}

void Game::deleteDeck(vector<GameCard*> &_deck) {
	for (int i = 0; i < _deck.size(); i++)
	{

		delete _deck[i];
		_deck[i] = NULL;
	}

}

void Game::makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket)
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
	_powerPlantMarket.push_back(p8);


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

void Game::shuffle(vector<GameCard*> &_deck) {
	random_shuffle(_deck.begin(), _deck.end());
}

GameCard* Game::drawCard(vector<GameCard*> &deck) {
	GameCard *temp = deck.at(0);
	if (temp->getIdentifier() == "s3")
	{
		//ENTERING STEP 3
		step = 3;
	}
	deck.erase(deck.begin());
	return temp;
}


//METHODS FOR POWER PLANT MARKET
void Game::sortMarket(vector<GameCard*> &_powerPlantMarket) {
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}


//METHODS FOR PHASE 2 : AUCTION
//
//
bool Game::isNumber(string s) {
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

void Game::Pass(Player * pl) {
	cout << "No powerplant interests " << pl->getName() << "." << endl;
	cout << endl;
}

string Game::Auction(PowerPlant * &powerplant, vector<Player*> &players, Player * pl) {
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

vector<GameCard*> Game::EnterAuctioningPhase(vector<GameCard*> &ppMarket, vector<Player*> &players) {
	vector<PowerPlant*> powerPlantMarket_; //copy 
	
	
	
	for (int i = 0; i < ppMarket.size(); i++) {
		powerPlantMarket_.push_back(static_cast<PowerPlant*>(ppMarket[i]));
	}

	//task 2 - phase 2
	string removePP;
	string input;

	for (int i = 0; i < players.size(); i++) {

		//sorting market and placing it in copy :: THERE WILL BE A PROBLEM WHEN THE STEP3 CARD IS DRAWN FROM THE DECK ***
		
		


		for (int j = 0; j < powerPlantMarket_.size(); j++) {
			powerPlantMarket_[j]->toString();
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
			for (int k = 0; k < powerPlantMarket_.size(); k++) { //check if powerplant number is available
				if (std::stoi(input) == powerPlantMarket_[k]->getCardNumber()) {
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
				for (int k = 0; k <= powerPlantMarket_.size(); k++) { //check if powerplant number is available
					if (std::stoi(input) == powerPlantMarket_[k]->getCardNumber()) {
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
			cout << players[i]->getName() << " has chosen to Auction (A) for powerplant: " << powerPlantMarket_[targetpp]->getCardNumber() << endl;
			//ENTER AUCTION!!!!
			removePP = Auction(powerPlantMarket_[targetpp], players, players[i]);
			cout << endl;

			//remove the bought powerplant from the market
			for (int m = 0; m < powerPlantMarket_.size(); m++) {
				if (removePP == powerPlantMarket_[m]->getIdentifier()) {
					powerPlantMarket_.erase(powerPlantMarket_.begin() + m);
				}
			}
			for (int m = 0; m < ppMarket.size(); m++) {
				if (removePP == ppMarket[m]->getIdentifier()) {
					ppMarket.erase(ppMarket.begin() + m);
				}
			}

			GameCard *temp = deck.at(0);
			if (temp->getIdentifier() == "s3")
			{
				//ENTERING STEP 3
				step = 3;
			}

			//THIS ISN'T ADDING A CART TO THE MARKET< PROBLEM TO BE FIXED.
			powerPlantMarket.push_back(temp);
			ppMarket.push_back(temp);
			//supposed to place it somewhere on the market
			deck.erase(deck.begin());
		

			

		}
	}

	//display the posessions of each player
	for (int i = 0; i < players.size(); i++) {
		players[i]->toString();
		cout << endl;
	}

	return ppMarket;
}


//METHODS FOR PHASE 4: BUREAUCRACY
int Game::checkProfit(int _num)
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

//WIN CONDITION
void Game::setNumCitiesWIN(int numPlayers)
{
	if (numPlayers == 2)
	{
		numCitiesWIN = 21;
	}
	else if (numPlayers == 3)
	{
		numCitiesWIN = 17;
	}
	else if (numPlayers == 4)
	{
		numCitiesWIN = 17;
	}
	else if (numPlayers == 5)
	{
		numCitiesWIN = 15;
	}
	else if (numPlayers == 6)
	{
		numCitiesWIN = 14;
	}
}
int Game::getNumCitiesWIN()
{
	return numCitiesWIN;
}

//STEP 2 CONDITION
void Game::setNumCitiesSTEP2(int numPlayers)
{
	if (numPlayers == 2)
	{
		numCitiesSTEP2 = 10;
	}
	else if (numPlayers == 3)
	{
		numCitiesSTEP2 = 7;
	}
	else if (numPlayers == 4)
	{
		numCitiesSTEP2 = 7;
	}
	else if (numPlayers == 5)
	{
		numCitiesSTEP2 = 7;
	}
	else if (numPlayers == 6)
	{
		numCitiesSTEP2 = 6;
	}
}
int Game::getNumCitiesSTEP2()
{
	return numCitiesSTEP2;
}

//METHODS FOR MAIN GAME LOOPS OF THE GAME
//
//
//
void Game::deckSetup()
{
	makingDeck(deck, powerPlantMarket);
	sortMarket(powerPlantMarket);
}

void Game::setUpPlayers()
{
	//============================== Assignment 2, task 1, ================================================
	// Select the number of players in the game
	std::cout << "How many players? (2-6):";
	
	string playerName = "";
	string color = "";
	string aiorhuman = "";
	

	vector<string> colors;
	colors.push_back("Red");
	colors.push_back("Blue");
	colors.push_back("Black");
	colors.push_back("Purple");
	colors.push_back("Green");
	int colorsSize = colors.size();

	//static vector<Player*> players;

	std::cin >> amountOfPlayers;

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

	//setting win condition
	setNumCitiesWIN(amountOfPlayers);
}

void Game::setUpMap()
{

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
	//GraphBuilder graph = GraphBuilder(amountOfVertices, mapFilename);
	graph = new GraphBuilder(amountOfVertices, mapFilename);

	std::cout << "are chosen regions connected?: " << graph->areChosenRegionsConnected(chosenRegCols) << std::endl;
	std::cout << std::endl;
	std::cout << "do all regions have exactly 7 cities?:" << graph->eachRegionHasSevenCities() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have duplicate edge(s)?:" << graph->hasDuplicateEdge() << std::endl;
	std::cout << std::endl;
	std::cout << "does map have missing edge(s)?:" << graph->hasMissingEdge() << std::endl;

	std::cout << std::endl;

	while (graph->hasDuplicateEdge() || graph->hasMissingEdge()) {
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
		graph = new GraphBuilder(amountOfVertices, mapFilename);

		std::cout << "are chosen regions connected?: " << graph->areChosenRegionsConnected(chosenRegCols) << std::endl;
		std::cout << std::endl;
		std::cout << "do all regions have exactly 7 cities?:" << graph->eachRegionHasSevenCities() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have duplicate edge(s)?:" << graph->hasDuplicateEdge() << std::endl;
		std::cout << std::endl;
		std::cout << "does map have missing edge(s)?:" << graph->hasMissingEdge() << std::endl;

		std::cout << std::endl;
	}

	std::cout << "The map is valid." << std::endl;
}

void Game::phase1_determinePlayerOrder()
{
	vector<int> playerOrder;

	if (round == 1) 
	{
		for (int i = 0; i < players.size(); i++) 
		{
			playerOrder.push_back(i);
		}

		//give random turn to each player
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(playerOrder.begin(), playerOrder.end(), g);

		cout << "Initial player order: " << endl;
		cout << endl;

		for (int i = 0; i < players.size(); i++) 
		{
			players.at(i)->setplayerOrder(playerOrder[i]);
		}

		//sort the order of the vertex
		std::sort(players.begin(), players.end(), Player::compByOrder);
		for (int i = 0; i < players.size(); i++) 
		{
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "Current player order: " << endl;
		cout << endl;

		//sort players by the number of cities they have (for the rest of the game)
		std::sort(players.begin(), players.end(), Player::compByCities);

		for (int i = 0; i < players.size(); i++) 
		{
			players.at(i)->setplayerOrder(i);
		}

		for (int i = 0; i < players.size(); i++)
		{
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}
		cout << endl;
	}
}

void Game::phase3_buyingResources()
{
	phase1_determinePlayerOrder();
	//-------------------TASK 3 --- BUYING RESOURCES -------------------------------------------- //
	int phase = 1;
	string pause;
	for (int i = 0; i < players.size(); i++) {

		cout << "------------------------------" << endl;

		cout << "\nYour turn " + players[i]->getName() + "!" << endl;
		cout << "\nEnter any character to see your dashboard..." << endl;
		cin >> pause;
		dashboard(players[i]);
		//for (int i = 0; i < playerOrder.size(); i++) {
		//cout << "Your turn " + playerOrder[i]->getName() << endl;

		bool stillBuying = true;

		vector <PowerPlant*> powerPlantsTEMP;
		powerPlantsTEMP = players[i]->getPowerPlant();

		while (stillBuying) {


			cout << "\nEnter any character to see the market..." << endl;
			cin >> pause;

			//display Resource Market
			market->display();


			//make this better in future by creating an exception that catches this...
			//*** I THINK TEMP NEEDS TO BE POINTER SO THAT IT CAN STOCKRT THE POWERPLANTS OWNED BY PLAYER

			if (powerPlantsTEMP.size() == 0) {
				cout << "Sorry you do not own a PowerPlant and therefore cannot buy resources." << endl;
				cout << "Your turn is over." << endl;
				cout << endl;
				stillBuying = false;
				break;
			}
			else {
				bool isMatch = false;
				string resource;

				while (isMatch != true) {

					cout << "\nWhich resources would you like to buy?" << endl;
					cin >> resource;

					bool notValidSource = true;

					while (notValidSource) {
						if (resource == "coal") {
							notValidSource = false;
							break;
						}
						else if (resource == "oil") {
							notValidSource = false;
							break;
						}
						else if (resource == "garbage") {
							notValidSource = false;
							break;
						}
						else if (resource == "uranium") {
							notValidSource = false;
							break;
						}
						else {
							notValidSource = true;
							cout << "That is an invalid resource. Please choose another resource: " << endl;
							cin >> resource;
						}
					}


					cout << "You chose " << resource << "." << endl;
					cout << endl;

					//check resource supply from Market
					bool hasSome = market->checkMarket(resource, 1);
					while (!hasSome) {
						cout << "The market is all out of " << resource << "." << endl;
						cout << "Please choose another resource: " << endl;
						cin >> resource;

						while (notValidSource) {
							if (resource == "coal") {
								notValidSource = false;
								break;
							}
							else if (resource == "oil") {
								notValidSource = false;
								break;
							}
							else if (resource == "garbage") {
								notValidSource = false;
								break;
							}
							else if (resource == "uranium") {
								notValidSource = false;
								break;
							}
							else {
								notValidSource = true;
								cout << "That is an invalid resource. Please choose another resource: " << endl;
								cin >> resource;
							}
						}

						hasSome = market->checkMarket(resource, 1);
					}



					bool inPowerPlant = false;

					//check if resources match ones on Player's powerplants
					for (int x = 0; x < powerPlantsTEMP.size(); x++) {
						inPowerPlant = powerPlantsTEMP[x]->checkRT(resource, 1);
						if (inPowerPlant) {
							cout << "Power plant " << powerPlantsTEMP[x]->getCardNumber() << " can be powered with this resource." << endl;
							cout << endl;
							isMatch = true;
							break;
						}
						else {
							cout << "Power plant " << powerPlantsTEMP[x]->getCardNumber() << " cannot be powered with this resource." << endl;
							cout << endl;
						}
					}

					//stockRT() instead it also checks space available in powerplant*****
					char yn;
					if (inPowerPlant == false) {
						cout << "You cannot buy this resource because you do not have a corresponding resource in your PowerPlants." << endl;
						cout << "\nWould you like to try to buy another resource?(Y/N)" << endl;
						cin >> yn;

						while (yn != 'Y' && yn != 'N') {
							cout << "This input is not valid. Please type in Y (for Yes) or N (for No): " << endl;
							cin >> yn;
						}

						if (yn == 'Y') {
							continue;
						}
						if (yn == 'N') {
							cout << "\nYour turn is over." << endl;
							cout << endl;
							stillBuying = false;
							goto breakhere;
						}
					}
				}


				//check if player can afford resource
				if (market->getPrice(resource) >= players[i]->getTotalWallet()) {
					cout << "Sorry you do not have enough Elektros to buy the resource. Your turn is over." << endl;
					stillBuying = false;
					break;
				}

				else {
					//check ResourceMarket price for resource
					cout << "You will pay " << market->getPrice(resource) << " Elektros for " << resource << "." << endl;

					//bill variables
					int bill1 = 0;
					int bill10 = 0;
					int bill50 = 0;
					int tempPrice = market->getPrice(resource);
					int totalSpent = 0;


					//this code below works
					bill50 = (tempPrice - tempPrice % 50) / 50;
					tempPrice -= bill50 * 50;
					bill10 = (tempPrice - tempPrice % 10) / 10;
					tempPrice -= bill10 * 10;
					bill1 = tempPrice;

					cout << "That will cost you " << bill50 << " x $50 Elektro bills, " << bill10 << " x $10 Elektro bills, and " << bill1 << " x $1 Elektro bills." << endl;
					players[i]->spendElektros(bill1, bill10, bill50);


					cout << "\nYou now have " << players[i]->getTotalWallet() << " Elektros." << endl;
					cout << endl;
					cout << "PowerPlants Owned: " << endl;


					//display just the card number of the powerplants you own
					for (int z = 0; z < powerPlantsTEMP.size(); z++) {
						cout << "PowerPlant number: " << powerPlantsTEMP[z]->getCardNumber() << endl;
					}


					//prompt player to select which powerplant to add resource to
					bool notValid = true;
					int selectPlant = 0;
					cout << "\nPlease enter the card number of the PowerPlant you want to add the " << resource << " to: " << endl;
					cin >> selectPlant;

					bool wrongNum = true;
					int indexPlant = 0;

					//***BUG: YOU CAN ADD RESOURCE TO ONE OF YOUR POWERPLANTS THAT DOESNT TAKE THAT RESOURCE HERE*****

					//check if a valid card number 
					for (int y = 0; y < powerPlantsTEMP.size(); y++) {
						if (selectPlant == powerPlantsTEMP[y]->getCardNumber()) {
							indexPlant = y;
							wrongNum = false;
							break;
						}
						else {
							wrongNum = true;
							continue;
						}
					}


					//CHECK HERE IF THAT POWERPLANT CAN TAKE THAT RESOURCE
					//// ***** the resource that isn't valid to that power plant is still added


					while (wrongNum) {
						cout << "Sorry that is not the card number of a PowerPlant you own. Try another card number. " << endl;
						cout << "\nPlease enter the card number of the PowerPlant you want to add the " + resource + " to: " << endl;
						cin >> selectPlant;

						//check if a valid card number ****Might cause error****
						for (int k = 0; k <powerPlantsTEMP.size(); k++) {
							if (selectPlant == powerPlantsTEMP[k]->getCardNumber()) {
								wrongNum = false;
								break;
							}
							else {
								continue;
							}
						}

					}

					//selectPlant is card number not index

					//add resource to player's appropriate powerplant
					powerPlantsTEMP[indexPlant]->stockRT(resource, 1);


					cout << "\nResource has been added to the PowerPlant... " << endl;

					//display Player's PowerPlants
					for (int z = 0; z < powerPlantsTEMP.size(); z++) {
						powerPlantsTEMP[z]->toString();
					}

					//remove from market
					market->rtPurchase(resource, 1);


					char yesno;
					cout << "\nWould you like to buy another resource? (Y/N)" << endl;
					cin >> yesno;

					while (yesno != 'Y' && yesno != 'N') {
						cout << "That is an invalid response. Please try again (Y/N): " << endl;
						cin >> yesno;
					}

					if (yesno == 'Y') {
						continue;
					}
					else {
						cout << "\nYour turn is over. " << endl;
						//It is " + players[i + 1]->getName() + "'s turn next!" << endl;
						cout << endl;
						stillBuying = false;
						break;
					}


					//Check powerplant class to make sure it can hold up to 2x resources

					//Ask user if (bool finishedBuying = true)? If not continue to loop

					//**do at the end** Prompt user if they want to transfer their resources from on plant to the other


					//make sure each player gets a turn

				}	//end of else statement regarding player having enough electrons

			}	//end of else statement saying you have a powerplant therefore can buy resource


		}	// while Still Buying Loop

	breakhere:continue;
	}		//end of Player for loop

			//phase = 3;
			//if (phase == 3) {

			//player loop


}

void Game::phase4_building()
{
	phase1_determinePlayerOrder();
	string pause;
	cout << "**********Now it is time to buy Cities!*********" << endl;
	cout << endl;


	//call method to reverse player order ***Use std::sort***
	//sort(players.begin(), players.end(), Player::reverseOrder);


	for (int i = 0; i < players.size(); i++) {
		vector<City> checkCity = players[i]->getCitiesOwned();
		string chosenCity;
		int numCities = checkCity.size();

		cout << "\nYour turn " << players[i]->getName() << "!" << endl;
		cout << endl;

		cout << "You have " << numCities << " cities so far." << endl;

		//for (int i = 0; i < playerOrder.size(); i++) {
		//cout << "Your turn " + playerOrder[i]->getName() << endl;

		bool stillBuilding = true;

		while (stillBuilding) {
			int cityPrice = 0;
			//display map with available cities
			//*TO-DO



			if (checkCity.size() == 0) {

				cout << "\nEnter any character to show list of cities on your map..." << endl;
				cin >> pause;


				cout << "\nList of available Cities: " << endl;
				graph->printAvailableCities();

				cout << "\nChoose a city anywhere on the available map: " << endl;

				cin >> chosenCity;


				//TO-DO check is chosenCity is even a valid German city name

				//check if chosenCity is part of the available map

				//check all conditions in the previous code (**later make this its own method in Game.h**)
				//check if chosenCity is part of the available map
				graph->SearchCity(chosenCity);		//displays info about a city

				bool validCity = graph->findCityByNameBool(chosenCity);	//bool updates player and map and checks if city is available

																		//check if in valid part of region
				while (!validCity) {

					cout << "This city is not in an available region of the map. Please choose another city: " << endl;

					cin >> chosenCity;

					graph->SearchCity(chosenCity);
					//validCity = graph.add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);		//ITS ALREADY ADDED ITSELF TO THE CITY!!

				}


				cout << "\nYou found a city that is available!" << endl;
				cout << "\nNow lets check some more conditions..." << endl;
				cout << endl;



				//check if the city is already filled with other players
				bool emptyCity = false;


				bool cityBought = false;
				bool isAdjacent = false;
				int price = 0;
				string tempCity;



				cityBought = false;


				//check players wallet based on city prices, if they have less than city price
				if (cityPrice >= players[i]->getTotalWallet()) {
					cout << "You have " << players[i]->getTotalWallet() << "Eletros." << endl;
					cout << "Sorry that is not enough Elektros to buy a building for this city. Your turn is over." << endl;
					stillBuilding = false;
				}
				else {
					cityBought = true;
				}




				//check for phase
				switch (step) {			//step = 1 in demo round 
				case 1:
					cityPrice = 10;
					break;
				case 2:
					cityPrice = 15;
					break;
				case 3:
					cityPrice = 20;
					break;
				}



				if (cityBought) {
					graph->add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);		//Adding city and player to map
					int total = 0;
					cout << "The cost of the city is " << cityPrice << "." << endl;
					cout << endl;
					cout << "You have " << players[i]->getTotalWallet() << " Elektros." << endl;
					cout << "The total cost is " << (price + cityPrice) << "." << endl;


					cout << "You will pay " << (price + cityPrice) << " Elektros for " << chosenCity << "." << endl;

					//bill variables
					int bill1 = 0;
					int bill10 = 0;
					int bill50 = 0;
					int tempPrice = (price + cityPrice);
					int totalSpent = 0;


					//this code below works
					bill50 = (tempPrice - tempPrice % 50) / 50;
					tempPrice -= bill50 * 50;
					bill10 = (tempPrice - tempPrice % 10) / 10;
					tempPrice -= bill10 * 10;
					bill1 = tempPrice;

					cout << "That will cost you " << bill50 << " x $50 Elektro bills, " << bill10 << " x $10 Elektro bills, and " << bill1 << " x $1 Elektro bills." << endl;
					players[i]->spendElektros(bill1, bill10, bill50);


					cout << "\nYou now have " << players[i]->getTotalWallet() << " Elektros." << endl;
					cout << endl;


					cout << "You have bought " << chosenCity << "." << endl;
					cout << endl;

					//checking if entering step 2
					if (players[i]->getCitiesOwned().size() >= numCitiesSTEP2)
					{
						step = 2;
					}

					//CHECKING IF WIN *******************************************
					if (players[i]->getCitiesOwned().size() >= numCitiesWIN)
					{
						win = true;
						players[i]->setWin(true);
					}
				}



				char yesno;
				cout << "Would you like to buy another City? (Y/N)" << endl;
				cin >> yesno;

				while (yesno != 'Y' && yesno != 'N') {
					cout << "That is an invalid response. Please try again (Y/N): " << endl;
					cin >> yesno;
				}

				if (yesno == 'Y') {
					continue;
				}
				else {
					cout << "Your turn is over." << endl;
					//<< players[i + 1]->getName() << "'s turn next!" << endl;
					stillBuilding = false;
					goto endhere;
				}

			} //end of else statement: player has more than one city...


			  //IF PLAYER HAS MORE THAN ONE CITY....
			else {
				// prompt player for city name


				cout << "\nEnter any character to show list of cities on your map..." << endl;
				cin >> pause;


				cout << "\nList of available Cities: " << endl;
				graph->printAvailableCities();

				cout << "\nChoose a city to build on that is adjacent to one of your cities: " << endl;

				cin >> chosenCity;

				//check all conditions in the previous code (**later make this its own method in Game.h**)
				//check if chosenCity is part of the available map
				graph->SearchCity(chosenCity);		//displays info about a city

				bool validCity = graph->findCityByNameBool(chosenCity);	//bool updates player and map and checks if city is available



																		//check if in valid part of region
				while (!validCity) {

					cout << "This city is not available. Please choose another city: " << endl;

					cin >> chosenCity;

					graph->SearchCity(chosenCity);
					//validCity = graph.add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);		//ITS ALREADY ADDED ITSELF TO THE CITY!!


				}


				cout << "\nYou found a city that is available!" << endl;
				cout << "\nNow lets check some more conditions..." << endl;
				cout << endl;






				//check if the city is already filled with other players
				bool emptyCity = false;

				bool cityBought = false;
				bool isAdjacent = false;
				int price = 0;
				string tempCity;


				//checks if chosen city is adjacent to Player's cities
				for (int m = 0; m < checkCity.size(); m++) {
					tempCity = checkCity[m].getCityName();
					isAdjacent = graph->IsCityAdjacentToOtherCity(chosenCity, tempCity);			///THIS THROWS ERROR
					if (isAdjacent) {
						price = graph->CostFromOneCityToAnother(chosenCity, tempCity);
						break;
					}
					else {
						continue;
					}
				}



				while (!isAdjacent) {		//*******This needs to loop back to incorporate earlier questions
					cout << "\nThe city you have chosen is not adjacent to any of your other cities. Please choose another city: " << endl;
					cin >> chosenCity;

					graph->SearchCity(chosenCity);		//displays info about a city
					cout << endl;

					for (int m = 0; m < checkCity.size(); m++) {
						isAdjacent = graph->IsCityAdjacentToOtherCity(chosenCity, checkCity[m].getCityName());
						if (isAdjacent) {
							price = graph->CostFromOneCityToAnother(chosenCity, checkCity[m].getCityName());
							break;
						}
						else {
							continue;
						}
					}
				}

				cityBought = false;

				//check for phase
				switch (step) {			//step = 1 in demo round 
				case 1:
					cityPrice = 10;
					break;
				case 2:
					cityPrice = 15;
					break;
				case 3:
					cityPrice = 20;
					break;
				}


				//check players wallet based on city prices, if they have less than city price
				if (cityPrice >= players[i]->getTotalWallet()) {
					cout << "You have " << players[i]->getTotalWallet() << "Eletros." << endl;
					cout << "Sorry that is not enough Elektros to buy a building for this city. Your turn is over." << endl;
					stillBuilding = false;
				}
				else {
					cityBought = true;
				}







				if (cityBought) {
					graph->add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);		//Adding city and player to map
					int total = 0;
					cout << "The cost of the city is " << cityPrice << "." << endl;
					cout << endl;
					cout << "You have " << players[i]->getTotalWallet() << " Elektros." << endl;
					cout << "The total cost is " << (price + cityPrice) << "." << endl;


					cout << "You will pay " << (price + cityPrice) << " Elektros for " << chosenCity << "." << endl;

					//bill variables
					int bill1 = 0;
					int bill10 = 0;
					int bill50 = 0;
					int tempPrice = (price + cityPrice);
					int totalSpent = 0;


					//this code below works
					bill50 = (tempPrice - tempPrice % 50) / 50;
					tempPrice -= bill50 * 50;
					bill10 = (tempPrice - tempPrice % 10) / 10;
					tempPrice -= bill10 * 10;
					bill1 = tempPrice;

					cout << "That will cost you " << bill50 << " x $50 Elektro bills, " << bill10 << " x $10 Elektro bills, and " << bill1 << " x $1 Elektro bills." << endl;
					players[i]->spendElektros(bill1, bill10, bill50);


					cout << "\nYou now have " << players[i]->getTotalWallet() << " Elektros." << endl;
					cout << endl;


					cout << "You have bought " << chosenCity << "." << endl;
					cout << endl;

				}



				char yesno;
				cout << "Would you like to buy another City? (Y/N)" << endl;
				cin >> yesno;

				while (yesno != 'Y' && yesno != 'N') {
					cout << "That is an invalid response. Please try again (Y/N): " << endl;
					cin >> yesno;
				}

				if (yesno == 'Y') {
					continue;
				}
				else {
					cout << "Your turn is over. " << endl;
						
						//It is " << players[i + 1]->getName() << "'s turn next!" << endl;
					stillBuilding = false;
					goto endhere;
				}

			} //end of else statement: player has more than one city...


			cout << "\nEnter any character to see your dashboard..." << endl;
			cin >> pause;
			dashboard(players[i]);


		} //stillBuilding while loop



	endhere:continue;
	}  //player loop
}

void Game::phase5_bureaucracy()
{
	string pause;


	phase1_determinePlayerOrder();


	//iterating through players
	for (int i = 0; i < players.size(); i++) {

		cout << "\nEnter any character to continue..." << endl;
		cin >> pause;
		vector<PowerPlant*> powerPlantsTEMP;
		std::cout << "Your turn " + players[i]->getName() + "!" << endl;
		std::cout << endl;

		if(players[i]->getCitiesOwned().size()!=0)
		{
			std::cout << "You own " << players[i]->getCitiesOwned().size() << (players[i]->getCitiesOwned().size() >= 2 ? " cities." : " city.") << endl;
		}

		
		powerPlantsTEMP = players[i]->getPowerPlant();

		if (players[i]->getPowerPlant().size() != 0)
		{
			std::cout << "You own " << players[i]->getPowerPlant().size() << (players[i]->getPowerPlant().size() >= 2 ? " power plants." : " power plant.") << endl;
		}
		//iterating through powerplants
		if (players[i]->getCitiesOwned().size() == 0) 
		{
			std::cout << "You do not own any cities and therefore cannot use any power plants. " << endl;
			cout << "\nEnter any character to continue..." << endl;
			cin >> pause;

		}
		else if (players[i]->getPowerPlant().size() == 0)
		{
			std::cout << "You do not own any power plants and therefore cannot power any cities. " << endl;
			cout << "\nEnter any character to continue..." << endl;
			cin >> pause;

		}
		else
		{
			
			for (int i = 0; i < powerPlantsTEMP.size(); i++)
			{
				std::cout << "================" << endl;
				std::cout << "Iterating through your power plants" << endl;
				std::cout << "================" << endl;
				powerPlantsTEMP[i]->toString();

				std::cout << "Would you like to power " << powerPlantsTEMP[i]->getCitiesPowered() 
				<< (powerPlantsTEMP[i]->getCitiesPowered() >= 2 ? " cities" : " city") << " with this powerplant? yes or no" << endl;

				cin >> choice;
				bool valid = false;
				bool inputValid = false;

			//NEED TO CHECK INPUT
				while (!inputValid)
				{


					if (choice == "yes")
					{
						std::cout << "With which resource?" << endl;
						while (!valid)
						{
							cin >> choice;
							if (choice == "coal" || choice == "oil" || choice == "garbage" || choice == "uranium")
							{
								if (powerPlantsTEMP[i]->checkIfEnoughStock(choice) && powerPlantsTEMP[i]->checkIfNeeded(choice))
								{
									powerPlantsTEMP[i]->powerCity(choice);
									market->addToSupply(choice, powerPlantsTEMP[i]->getRTNeeded(choice));


									//market->toString();
									valid = true;
								}
								else if (!powerPlantsTEMP[i]->checkIfEnoughStock(choice))
								{
									std::cout << "You do not have enough " << choice << " stocked to use this power plant." << endl;
									std::cout << "Proceeding to next power plant." << endl;
									valid = true;
								}
								else
								{
									//std::cout << "Not enough in stock!! OR This resource isn't needed for this powerplant" << endl;
									std::cout << "Please enter valid input." << endl;
									valid = false;
								}



							}
							else
							{
								std::cout << "Enter a valid input please." << endl;
								valid = false;
							}
						}

						inputValid = true;
					}
					else if (choice == "no")
					{
						std::cout << "Next Power Plant: " << endl;
						std::cout << endl;
						std::cout << endl;
						inputValid = true;
					}
					else
					{
						inputValid = false;
					}
				}
				numCitiesPowered += powerPlantsTEMP[i]->get_numCitiesPowered_ACTIVE();
				//can only power the number of cities they own MAX, otherwise waisted energy

				vector<City> temp = players[i]->getCitiesOwned();

				if (numCitiesPowered > temp.size())
				{
					std::cout << "You are trying to power " << numCitiesPowered << " cities with your power plants while you only own " << temp.size() << endl;
					std::cout << "You are wasting energy." << endl;
					numCitiesPowered = temp.size();
					
				}
			}

		}
		std::cout << "By powering " << numCitiesPowered << " cities, you earn: " << checkProfit(numCitiesPowered) << endl;

		profit = checkProfit(numCitiesPowered);
		std::cout << "================" << endl;
		std::cout << "Initial Wallet: " << endl;
		std::cout << "================" << endl;
		players[i]->walletToString();
		bill50 = (profit - profit % 50) / 50;
		profit -= bill50 * 50;
		bill10 = (profit - profit % 10) / 10;
		profit -= bill10 * 10;
		bill1 = profit;
		players[i]->collectElektro(bill1, bill10, bill50);
		std::cout << endl;

		std::cout << "================" << endl;
		std::cout << "Updated Wallet: " << endl;
		std::cout << "================" << endl;

		players[i]->walletToString();

		//players[i]->toString();
	}

	//removing most expensive Power plant from the market and placing it under the draw deck
	GameCard *MostExpensive = powerPlantMarket.at(powerPlantMarket.size() - 1);
	powerPlantMarket.pop_back();
	deck.push_back(MostExpensive);

	//drawing new card from deck and adding it the power plant market
	GameCard *newCard = deck.at(0);

	if (newCard->getIdentifier() == "s3")
	{
		step = 3;
	}
	deck.erase(deck.begin());
	powerPlantMarket.push_back(newCard);
	//placing the cards in ascending order of price
	sortMarket(powerPlantMarket);

	//market changes according to step in the game
	//Do we need to implement this?
	if (step == 1)
	{

	}
	else if (step == 2)
	{

	}
	else if (step == 3)
	{

	}

	//restock market
	market->restockMarket(step);


}

void Game::dashboard(Player* p) {
	//cout resources from powerplants, cities, etc

	cout << "\n--------------------------" << endl;
	cout << p->getName() + "'s Dashboard: " << endl;
	cout << "\n--------------------------" << endl;
	cout << "PowerPlants:";
	
	//Display list of player's powerplants
	//***need to reformat powerplant toString so that it looks better in dashboard***
	//NEEDS DEBUGGING
	if (p->getPowerPlant().size() == 0) {
		cout << "You have 0 powerplants." << endl;
	}

	for (int i = 0; i < p->getPowerPlant().size(); i++) {
		p->getPowerPlant()[i]->toString();
		cout << endl;
	}
	
	cout << endl;
	cout << "Cities:\n" << endl;

		cout << "You have "<< p->getCitiesOwned().size() << " cities." << endl;
		cout << endl;

	for (int i = 0; i < p->getCitiesOwned().size(); i++) {
		p->getCitiesOwned()[i].getCityName();
		cout << endl;
	}


	cout << "\nElektros:\n" << endl;
	p->walletToString();
	cout << endl;
	
	cout << "\nResources:\n" << endl;
	
	//cycle through player's powerplant vectors to see which resources they own

	int player_coal = 0;
	int player_oil = 0;
	int player_garbage = 0;
	int player_uranium = 0;
	vector <PowerPlant *> c = p->getPowerPlant();

	for (int i = 0; i < c.size(); i++) {
		player_coal += c[i]->getRTStocked("oil");
		player_oil += c[i]->getRTStocked("oil");
		player_garbage += c[i]->getRTStocked("garbage");
		player_uranium += c[i]->getRTStocked("uranium");
		/*
		player_oil += p->getPowerPlant()[i].getRTStocked("oil");
		player_garbage += p->getPowerPlant()[i].getRTStocked("garbage");
		player_uranium += p->getPowerPlant()[i].getRTStocked("uranium");
		*/
	}

	cout << "Amount of Coal Owned: " << player_coal << endl;
	cout << "Amount of Oil Owned: " << player_oil << endl;
	cout << "Amount of Garbage Owned: " << player_garbage << endl;
	cout << "Amount of Uranium Owned: " << player_uranium << endl;
	cout << "\n--------------------------" << endl;



}

void Game::play()
{
	cout << "\n***********************************************************" << endl;
	cout << "\n***********************************************************" << endl;
	cout << "WELCOME TO POWERGRID ! LET'S SET UP THE GAME." << endl;
	cout << "\n***********************************************************" << endl;
	cout << "\n***********************************************************" << endl;

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Setting up the deck..." << endl;
	deckSetup();

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Setting up the players..." << endl;
	setUpPlayers();

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Setting up the map..." << endl;
	setUpMap();
	int roundNum = 1;

	string pause;

	while (!win)
	{
		cout << "\nEnter any character to continue to ROUND " << roundNum << "..." << endl;
		cin >> pause;

		cout << endl;
		cout << "------------------------------ ------------------------------ ------------------------------" << endl;
		cout << " ------------------------------ ROUND " << roundNum << " ------------------------------" << endl;
		cout << "------------------------------ ------------------------------ ------------------------------" << endl;
		cout << endl;

		cout << "\nEnter any character to continue to PHASE 1..." << endl;
		cin >> pause;

		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "PHASE 1 : DETERMINE PLAYER ORDER" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;

		phase1_determinePlayerOrder();
		Notify();
		cout << "\nEnter any character to continue to PHASE 2..." << endl;
		cin >> pause;

		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "PHASE 2 : AUCTION" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		
		EnterAuctioningPhase(powerPlantMarket, players);
		Notify();
		cout << "\nEnter any character to continue to PHASE 3..." << endl;
		cin >> pause;

		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "PHASE 3 : BUYING RESOURCES" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		
		phase3_buyingResources();
		Notify();
		cout << "\nEnter any character to continue to PHASE 4..." << endl;
		cin >> pause;

		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "PHASE 4 : BUILDING" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;

		//method where we are checking for win conditions, set up according to number of players and looks if a player owns a specific number of cities
		phase4_building();
		Notify();
		cout << "\nEnter any character to continue to PHASE 5..." << endl;
		cin >> pause;

		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "PHASE 5 : BUREAUCRACY" << endl;
		cout << "\n***********************************************************" << endl;
		cout << "\n***********************************************************" << endl;

		phase5_bureaucracy();
		Notify();

		//printing the winner
		for (int i = 0; i < players.size(); i++)
		{
			if (players[i]->getWin())
			{
				cout << " PLAYER " << players[i]->getName() << " HAS WON THE GAME !!!!!!!" << endl;
				Notify();
				break;
			}
		}

		roundNum++;
	}
}
