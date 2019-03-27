//main for task 3

#include "Game.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "GraphBuilder.h"
#include "City.h"
#include "Elektro.hpp"
#include "Market.hpp"
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


static void print(vector<GameCard*> &_deck) {
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

static void sortMarket(vector<PowerPlant*> &_powerPlantMarket)
{
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}

static void Auction(PowerPlant * powerplant, vector<Player*> players, Player * pl) {
	cout << endl;
	cout << "$$$$$$ Give your best price! $$$$$$" << endl;
	cout << endl;
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
		}

		//sort the order of the vertex
		std::sort(players.begin(), players.end(), Player::compByOrder);
		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}

		cout << endl;
	}


	else if (round == 2 || round == 3) {
		cout << "Current player order: " << endl;
		cout << endl;

		//reverse player order
		std::sort(players.begin(), players.end(), Player::reverseOrder);

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(i);
		}

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



int main() {

	//========================================TASK 1===================================================

	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "powergrid_cities.map");
	graph.buildMap();

	//TASK 2 (Rose)
	//============================== Assignment 2, task 2, ================================================
	static vector<GameCard*> deck;
	static vector<PowerPlant*> powerPlantMarket;
	static int phase = 1;


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

	while (gameIsNotFinished == false) {

		while (round >= 1) {

			//task 2 - step 1
			DeterminePlayerOrder(players, round);

			round += 1;
			DeterminePlayerOrder(players, round);
			std::sort(players.begin(), players.end(), Player::compByOrder);


			//task2 - step 2
			for (int i = 0; i < players.size(); i++) {
				for (int j = 0; j < powerPlantMarket.size(); j++) {
					powerPlantMarket[j]->toString();
				}
				cout << players[i]->getName() << ", would you like to Pass or Auction a powerplant?" << endl;
				cout << endl;
				cout << "If you would like to Pass, press 'P'. If you would like to Auction a powerplant, enter the card number of the powerplant you want: ";
				cin >> input;
				cout << endl;

				//find if card is available
				bool isCardInVector;
				int targetpp;
				for (int k = 0; k <= powerPlantMarket.size(); k++) {
					if ((input - 48) == powerPlantMarket[k]->getCardNumber()) {
						targetpp = k;
						isCardInVector = true;
						break;
					}
					else
						isCardInVector = false;
				}

				while (input != 'P' && isCardInVector == false) {
					cout << "This input is not valid. Please type in P (for Pass) or powerplant card number: ";
					cin >> input;
					cout << endl;
				}
				if (input == 'P') {
					//Player::Pass();
				}
				if (isCardInVector) {
					cout << players[i]->getName() << " has chosen to Auction (A) for powerplant: " << powerPlantMarket[targetpp]->getCardNumber() << endl;
					Auction(powerPlantMarket[targetpp], players, players[i]);
					cout << endl;
					break;
				}
			}

			round = 0;
		}
		gameIsNotFinished = true;
	}
	deleteDeck(deck);


	/*PowerPlant test1(2, 2, 3, 2, 0, 0);

	vector<PowerPlant> p1vect{};

	Player* p1 = players[0];

	p1vect.push_back(test1);
	p1->setPowerPlant(p1vect);*/

	/* //this works//
	vector <PowerPlant> show = p1.getPowerPlant();

	for (int i =0; i < show.size(); i++) {
		show[i].toString();
	}*/

	//game1.dashboard(p1);


	//TASK 3 --- BUYING RESOURCES --- //

	//bool gameIsNotFinished = true;
	round = 2;

	while (gameIsNotFinished) {

		if (round == 2) {

			DeterminePlayerOrder(players, round);

			//call method to reverse player order ***Use std::sort***
			//sort(players.begin(), players.end(), Player::reverseOrder);

			for (int i = 0; i < players.size(); i++) {


				cout << "Your turn " + players[i]->getName() + "!" << endl;
				//for (int i = 0; i < playerOrder.size(); i++) {
					//cout << "Your turn " + playerOrder[i]->getName() << endl;

				bool stillBuying = true;

				while (stillBuying) {


					//display Resource Market
					market.display();

					//make this better in future by creating an exception that catches this...
					//*** I THINK TEMP NEEDS TO BE POINTER SO THAT IT CAN STOCKRT THE POWERPLANTS OWNED BY PLAYER
					vector <PowerPlant> temp = players[i]->getPowerPlant();
					if (temp.size() == 0) {
						cout << "Sorry you do not own a PowerPlant and therefore cannot buy resources." << endl;
					}
					else {
						bool isMatch = false;
						string resource = NULL;

						while (isMatch != true) {

							cout << "Which resources would you like to buy?" << endl;
							cin >> resource;

							while (resource != "coal" || resource != "oil" || resource != "garbage" || resource != "uranium") {
								cout << "That input is not valid. Which resources would you like to buy?" << endl;
								cin >> resource;
							}

							cout << "You chose " << resource << endl;

							//check if resources match ones on Player's powerplants
							for (int i = 0; i < temp.size(); i++) {
								isMatch = temp[i].checkIfNeeded(resource);
								if (isMatch) {
									break;
								}
							}

							cout << "Sorry you cannot buy this resource because you do not have a corresponding resource in your PowerPlants." << endl;
						}

						//check if player can afford resource
						if (market.getPrice(resource) <= players[i]->getTotalWallet()) {
							cout << "Sorry you do not have enough Elektros to buy the resource. Your turn is over." << endl;
							stillBuying = false;
						}

						else {
							//check ResourceMarket price for resource
							cout << "You will pay " + market.getPrice(resource) << " Elektros for " + resource << "." << endl;

							//bill variables
							int bill1 = 0;
							int bill10 = 0;
							int bill50 = 0;

							int totalSpent = 0;

							cout << "\nEnter how you would like to pay. You must pay the exact amount using the Elektro bills you own." << endl;
							cout << "Number of $1 Elektro bills to use: " << endl;
							cin >> bill1;
							cout << "Number of $10 Elektro bills to use: " << endl;
							cin >> bill10;
							cout << "Number of $50 Elektro bills to use: " << endl;
							cin >> bill50;
							totalSpent = bill1 + bill10 + bill50;

							//while loop to ensure Player pays correct amount for resource
							while (totalSpent != market.getPrice(resource)) {
								cout << "Sorry that total does not equal the price of the resource." << endl;
								cout << "\nEnter how you would like to pay. You must pay the exact amount using the Elektro bills you own." << endl;
								cout << "Number of $1 Elektro bills to use: " << endl;
								cin >> bill1;
								cout << "Number of $10 Elektro bills to use: " << endl;
								cin >> bill10;
								cout << "Number of $50 Elektro bills to use: " << endl;
								cin >> bill50;
								totalSpent = bill1 + bill10 + bill50;

							}

							//remove amount of elektros from Player object
							players[i]->spendElektros(bill1, bill10, bill50);


							//display Player's PowerPlants
							for (int i = 0; i < temp.size(); i++) {
								temp[i].toString();
							}

							//prompt player to select which powerplant to add resource to
							bool notValid = true;
							int selectPlant = 0;
							cout << "Please enter the card number of the PowerPlant you want to add the " + resource + " to: " << endl;
							cin >> selectPlant;

							//check if a valid card number
							int j = 0;
							for (int j = 0; i < temp.size(); j++) {
								if (selectPlant == temp[j].getCardNumber()) {
									notValid = false;
									break;
								}
								else {
									continue;
								}
							}

							while (notValid) {
								cout << "Sorry that is not the card number of a PowerPlant you own. Try another card number: " << endl;
								cout << "Please enter the card number of the PowerPlant you want to add the " + resource + " to: " << endl;
								cin >> selectPlant;

								//check if a valid card number
								for (j = 0; i < temp.size(); j++) {
									if (selectPlant == temp[j].getCardNumber()) {
										notValid = false;
										break;
									}
									else {
										continue;
									}
								}

							}


							//add resource to player's appropriate powerplant
							temp[j].stockRT(resource, 1);

							//remove resource from Market
							market.sellResource(resource, 1);

							//while loop to check if match

							char yesno = NULL;
							cout << "Would you like to buy another resource? (Y/N)" << endl;
							cin >> yesno;

							while (yesno != 'Y' || yesno != 'N') {
								cout << "That is an invalid response. Please try again (Y/N): " << endl;
								cin >> yesno;
							}

							if (yesno == 'Y') {
								continue;
							}
							else {
								cout << "Your turn is over. It is " + players[i + 1]->getName() + "'s turn next!" << endl;
								stillBuying = false;
							}


							//Check powerplant class to make sure it can hold up to 2x resources

							//Ask user if (bool finishedBuying = true)? If not continue to loop

							//**do at the end** Prompt user if they want to transfer their resources from on plant to the other


							//make sure each player gets a turn

						}	//end of else statement regarding player having enough elektros

					}	//stillBuying while loop
				

			}	// for loop players
			
			round++;
		}		//if round == 2 condition

			if (round == 3) {

				//player loop
				DeterminePlayerOrder(players, round);

				//call method to reverse player order ***Use std::sort***
				//sort(players.begin(), players.end(), Player::reverseOrder);

				for (int i = 0; i < players.size(); i++) {


					cout << "Your turn " + players[i]->getName() + "!" << endl;
					//for (int i = 0; i < playerOrder.size(); i++) {
					//cout << "Your turn " + playerOrder[i]->getName() << endl;

					bool stillBuilding = true;

					while (stillBuilding) {

						//display map with available cities
							//*TO-DO

						vector<City> checkCity = players[i]->getCitiesOwned();
						string chosenCity = NULL;

						if (checkCity.size == 0 || round == 1) {		//**obvi this is in the round == 3 loop so this is wrong 
							cout << "You have 0 cities so far! Choose a city anywhere on the available map: " << endl;
							cin >> chosenCity;
						}

						//**TO-DO check is chosenCity is even a valid German city name

						//check if chosenCity is part of the available map
						bool validCity = false;

						//check if in valid part of region
						while (validCity != true) {
							graph.SearchCity(chosenCity);
							validCity = graph.cityAvailable(chosenCity);	//if validCity is true will the while loop break immediately?
							cout << "This city is not in an available region of the map. Please choose another city: " << endl;
							cin >> chosenCity;
						}		//validCity while loop

						//check if the city is already filled with other players
						bool emptyCity = false;

						while(emptyCity != true){

						//check for phase
						switch (phase) {
						case 1: if (graph.HowManyPlayersAreInCity(chosenCity) == 1) {
								cout << "Sorry, another player already has a building on this city. Please choose another city: ";
								cin >> chosenCity;
								validCity = false;
								}
								else {
									validCity = true;
								}
								return;
						case 2:  if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
								cout << "Sorry, another player already has a building on this city. Please choose another city: ";
								cin >> chosenCity;
								validCity = false;
								}
								 else {
									 validCity = true;
								 }
								return;
						case 3: if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
								cout << "Sorry, another player already has a building on this city. Please choose another city: ";
								cin >> chosenCity;
								validCity = false;
								}
								else {
									validCity = true;
								}
								return;
							}


						}	//emptyCity while loop

						cout << "You have selected " + chosenCity + ". This city is available to buy." << endl;

									//set City prices based on phase
									//check players wallet based on city prices, if they have less than city price
									// cout << “Insufficient funds” << endl
									//break out of the loop
									//cout << “You bought a house in “ + cityChoice << endl;
									//Graph. Add_citytoPlayer_And_playerToMap (players[i], cityChoice);
									//round up outside player for loop at end

									else(citiesOwned() > 0)


										//only for next loop
										(vector<City> checkCity = player[i]->getCitiesOwned())
										For(int i = 1; i < checkCity.size(); i++)
										String temp;
									Temp = checkCity[i].getCityName();




					} //stillBuilding while loop

				}	//player loop

			}	// round 3 if conditional statement

	}	//GameisNotFinished while loop

	
			

		

		//keep console open
		cin.get();



}	//int main()
