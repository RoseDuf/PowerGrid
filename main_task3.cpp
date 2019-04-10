//main for task 3

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Game.h"
#include "player.hpp"
#include "GraphBuilder.h"
#include "City.h"
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

static void print(vector<GameCard*> &_deck) {
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
			players.at(i)->setplayerOrder(i);
		}

		/*for (int i = 0; i < players.size(); i++) {
		players.at(i)->setplayerOrder(playerOrder[i]);
		}*/
		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << players.at(i)->getName() << endl;
		}
		cout << endl;
	}
	else if (phase == 2 || phase == 3) {
		cout << "Current player order:" << endl;
		cout << endl;

		//sort the order of the vertex
		std::sort(players.begin(), players.end(), Player::reverseOrder);

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(i);
		}
		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << players.at(i)->getName() << endl;
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
			cout << "Player: " << players.at(i)->getName() << endl;
		}
		cout << endl;
	}
}

static void sortMarket(vector<GameCard*> &_powerPlantMarket)
{
	sort(_powerPlantMarket.begin(), _powerPlantMarket.end());

}

// Returns true if s is a number else false 
static bool isNumber(string s) {
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

static void Pass(Player * pl) {
	cout << "No powerplant interests " << pl->getName() << "." << endl;
	cout << endl;
}


int main() {

	//========================================TASK 1===================================================

	//Initiate Graph and Build Map
	GraphBuilder graph = GraphBuilder(42, "germany.map");
	Game g1 = Game();

	//TASK 2 (Rose)
	//============================== Assignment 2, task 2, ================================================
	static vector<GameCard*> deck;
	static vector<GameCard*> powerPlantMarket;
	static int step = 1; //should be step

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

	Market market = Market(players);
	market.display();
	cout << "First one" << endl;


	makingDeck(deck, powerPlantMarket);
	//print(powerPlantMarket);
	//bureaucracy(deck, powerPlantMarket, market);
	//print(powerPlantMarket);
	sortMarket(powerPlantMarket);
	//print(powerPlantMarket);
	// print(powerPlantMarket);
	//shuffle(deck);
	//print(deck);
	//cout << deck.size() << endl;




	//set sample powerplants to players
	PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
	PowerPlant *p29 = new PowerPlant(31, 6, 3, 0, 0, 0);
	PowerPlant *p35 = new PowerPlant(37, 4, 0, 0, 0, 0);
	PowerPlant *p36 = new PowerPlant(38, 7, 0, 0, 3, 0);
	PowerPlant *p37 = new PowerPlant(39, 6, 0, 0, 0, 1);
	PowerPlant *p38 = new PowerPlant(40, 6, 0, 2, 0, 0);
	PowerPlant *p39 = new PowerPlant(42, 6, 2, 0, 0, 0);

	players[0]->addPowerPlant(p1);
	players[1]->addPowerPlant(p29);
	players[1]->addPowerPlant(p35);
	players[2]->addPowerPlant(p36);
	players[3]->addPowerPlant(p37);



	//Game loop !!!!
	bool gameIsNotFinished = true;
	int phase = 2;
	string pause;


	//-------------------TASK 3 --- BUYING RESOURCES -------------------------------------------- //

	phase = 1;
	DeterminePlayerOrder(players, phase);
	phase = 2;

	//while (gameIsNotFinished) {

	//if (phase == 2) {

	DeterminePlayerOrder(players, phase);

	//call method to reverse player order ***Use std::sort***


	for (int i = 0; i < players.size(); i++) {


		cout << "Your turn " + players[i]->getName() + "!" << endl;
		cout << "\nEnter any character to see your dashboard..." << endl;
		cin >> pause;
		g1.dashboard(players[i]);
		//for (int i = 0; i < playerOrder.size(); i++) {
		//cout << "Your turn " + playerOrder[i]->getName() << endl;

		bool stillBuying = true;

		while (stillBuying) {

			vector <PowerPlant*> powerPlantsTEMP;
			powerPlantsTEMP = players[i]->getPowerPlant();


			//display Resource Market
			market.display();


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

					bool inPowerPlant = false;

					//check if resources match ones on Player's powerplants
					for (int x = 0; x < powerPlantsTEMP.size(); x++) {
						inPowerPlant = powerPlantsTEMP[x]->checkIfNeeded(resource);
						if (inPowerPlant) {
							isMatch = true;
							break;
						}
					}

					//stockRT() instead it also checks space available in powerplant*****
					char yn;
					if (inPowerPlant == false) {
						cout << "Sorry you cannot buy this resource because you do not have a corresponding resource in your PowerPlants." << endl;
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
				if (market.getPrice(resource) >= players[i]->getTotalWallet()) {
					cout << "Sorry you do not have enough Elektros to buy the resource. Your turn is over." << endl;
					stillBuying = false;
					break;
				}

				else {
					//check ResourceMarket price for resource
					cout << "You will pay " << market.getPrice(resource) << " Elektros for " << resource << "." << endl;

					//bill variables
					int bill1 = 0;
					int bill10 = 0;
					int bill50 = 0;
					int tempPrice = market.getPrice(resource);
					int totalSpent = 0;


					//this code below works
					bill50 = (tempPrice - tempPrice % 50) / 50;
					tempPrice -= bill50 * 50;
					bill10 = (tempPrice - tempPrice % 10) / 10;
					tempPrice -= bill10 * 10;
					bill1 = tempPrice;

					cout << "That will cost you " << bill50 << " x $50 Elektro bills, " << bill10 << " x $10 Elektro bills, and " << bill1 << " x $1 Elektro bills." << endl;
					players[i]->spendElektros(bill1, bill10, bill50);



					//while loop to ensure Player pays correct amount for resource
					/*while (totalSpent != market.getPrice(resource)) {
					cout << "Sorry that total does not equal the price of the resource." << endl;
					cout << "\nEnter how you would like to pay. You must pay the exact amount using the Elektro bills you own." << endl;
					cout << "Number of $1 Elektro bills to use: " << endl;
					cin >> bill1;
					cout << "Number of $10 Elektro bills to use: " << endl;
					cin >> bill10;
					cout << "Number of $50 Elektro bills to use: " << endl;
					cin >> bill50;
					totalSpent = bill1 + bill10 + bill50;

					}*/

					//profit variable
					/*bill50 = ( tempPrice - tempPrice % 50) / 50;
					tempPrice -= bill5050;
					bill10 = (tempPrice - tempPrice % 10) / 10;
					tempPrice -= bill1010;
					bill1 = tempPrice;
					players[i]->collectElektro(bill1, bill10, bill50);
					*/

					//****Use isabelle's method from Discord --- its automatic!!****

					//remove amount of elektros from Player object


					cout << "\nYou now have " << players[i]->getTotalWallet() << " Elektros." << endl;

					//display Player's PowerPlants
					for (int z = 0; z < players[i]->getPowerPlant().size(); z++) {
						powerPlantsTEMP[z]->toString();
					}

					//prompt player to select which powerplant to add resource to
					bool notValid = true;
					int selectPlant = 0;
					cout << "\nPlease enter the card number of the PowerPlant you want to add the " << resource << " to: " << endl;
					cin >> selectPlant;

					//check if a valid card number ***BUG: YOU CAN ADD TO WRONG POWERPLANT HERE*****
					int y = 0;
					for (y = 0; y < players[i]->getPowerPlant().size(); y++) {
						if (selectPlant == powerPlantsTEMP[y]->getCardNumber()) {
							notValid = false;
							break;
						}
						else {
							continue;
						}
					}

					while (notValid) {
						cout << "Sorry that is not the card number of a PowerPlant you own. Try another card number. " << endl;
						cout << "Please enter the card number of the PowerPlant you want to add the " + resource + " to: " << endl;
						cin >> selectPlant;

						//check if a valid card number ****Might cause error****
						for (y = 0; y < players[i]->getPowerPlant().size(); y++) {
							if (selectPlant == powerPlantsTEMP[y]->getCardNumber()) {
								notValid = false;
								break;
							}
							else {
								continue;
							}
						}

					}


					//add resource to player's appropriate powerplant **** THIS GONNA ERROR***
					powerPlantsTEMP[y]->stockRT(resource, 1);
					cout << "\nResource has been added to the PowerPlant... " << endl;

					//remove resource from Market
					market.rtPurchase(resource, 1);

					//while loop to check if match

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
						cout << "\nYour turn is over. It is " + players[i + 1]->getName() + "'s turn next!" << endl;
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

	cout << "**********Now it is time to buy Cities!*********" << endl;
	cout << endl;
	DeterminePlayerOrder(players, phase);

	//call method to reverse player order ***Use std::sort***
	//sort(players.begin(), players.end(), Player::reverseOrder);


	for (int i = 0; i < players.size(); i++) {


		cout << "\nYour turn " << players[i]->getName() << "!" << endl;
		cout << endl;
		//for (int i = 0; i < playerOrder.size(); i++) {
		//cout << "Your turn " + playerOrder[i]->getName() << endl;

		bool stillBuilding = true;

		while (stillBuilding) {
			int cityPrice = 0;
			//display map with available cities
			//*TO-DO

			vector<City> checkCity = players[i]->getCitiesOwned();
			string chosenCity;

			if (checkCity.size() == 0) {
				cout << "\nYou have 0 cities so far! Choose a city anywhere on the available map: " << endl;
				cin >> chosenCity;


				//**TO-DO check is chosenCity is even a valid German city name

				//check if chosenCity is part of the available map
				bool validCity = false;

				//check if in valid part of region
				while (validCity != true) {
					graph.SearchCity(chosenCity);
					validCity = graph.add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);	//if validCity is true will the while loop break immediately?
					if (validCity = true) {
						break;
					}
					else {
						cout << "This city is not in an available region of the map. Please choose another city: " << endl;
						cin >> chosenCity;
					}
				}		//validCity while loop

						//check if the city is already filled with other players
				bool emptyCity = false;
				cityPrice = 0;

				while (emptyCity != true) {

					//check for phase
					switch (step) {
					case 1: if (graph.HowManyPlayersAreInCity(chosenCity) == 1) {
						cout << "Sorry, another player already has a building on this city. Please choose another city: ";
						cin >> chosenCity;
						validCity = false;
					}
							else {
								validCity = true;
							}
							cityPrice = 10;
							break;
					case 2:  if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
						cout << "Sorry, another player already has a building on this city. Please choose another city: ";
						cin >> chosenCity;
						validCity = false;
					}
							 else {
								 validCity = true;
							 }
							 cityPrice = 15;
							 break;
					case 3: if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
						cout << "Sorry, another player already has a building on this city. Please choose another city: ";
						cin >> chosenCity;
						validCity = false;
					}
							else {
								validCity = true;
							}
							cityPrice = 20;
							break;
					}


				}	//emptyCity while loop

				cout << "You have selected " << chosenCity << ". This city is available to buy." << endl;
				cout << "\nCalculating price..." << endl;
				cout << chosenCity << " costs " << cityPrice << " Elektros." << endl;


				//check players wallet based on city prices, if they have less than city price
				if (cityPrice >= players[i]->getTotalWallet()) {
					cout << "Sorry you do not have enough Elektros to a building for this city. Your turn is over." << endl;
					stillBuilding = false;
				}
				else {
					cout << "You bought a house in " << chosenCity << endl;
					graph.add_CityToPlayer_and_PlayerToMap(players[i], chosenCity);	//**this function adds city to player's city vector?
				}

			}	//end of if checkCities.size() == 0

			else {
				// prompt player for city name
				int numCities = checkCity.size();

				cout << "\nList of available Cities: " << endl;
				graph.printAvailableCities();

				cout << "\nYou have " << numCities << " cities so far! Choose a city to build on that is adjacent to one of your cities: " << endl;
				cin >> chosenCity;




				//check all conditions in the previous code (**later make this its own method in Game.h**)
				//check if chosenCity is part of the available map
				bool validCity = false;

				//check if in valid part of region
				while (!validCity) {
					graph.SearchCity(chosenCity);
					validCity = graph.add_CityToPlayer_and_PlayerToMap(players[i], chosenCity); //if validCity is true will the while loop break immediately?
					if (validCity == true) {
						break;
						validCity = true;
					}
					else {
						cout << "This city is not in an available region of the map. Please choose another city: " << endl;
						cin >> chosenCity;
						validCity = false;
					}
					//validCity while loop

					cout << "You found a city that is available!" << endl;
					cout << "Now lets check some more conditions..." << endl;
					cout << endl;
					//cout << "How many players in Halle"<< endl;
					//cout << graph.HowManyPlayersAreInCity(chosenCity);
					//check if the city is already filled with other players
					bool emptyCity = false;


					while (emptyCity != true) {

						//check for phase
						switch (step) {
						case 1: if (graph.HowManyPlayersAreInCity(chosenCity) == 1) {
							cout << "\nSorry, another player already has a building on this city. Please choose another city: ";
							cin >> chosenCity;
							validCity = false;
						}
								else {
									validCity = true;
								}
								cityPrice = 10;
								break;
						case 2:  if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
							cout << "\nSorry, another player already has a building on this city. Please choose another city: ";
							cin >> chosenCity;
							validCity = false;
						}
								 else {
									 validCity = true;
								 }
								 cityPrice = 15;
								 break;
						case 3: if (graph.HowManyPlayersAreInCity(chosenCity) == 2) {
							cout << "\nSorry, another player already has a building on this city. Please choose another city: ";
							cin >> chosenCity;
							validCity = false;
						}
								else {
									validCity = true;
								}
								cityPrice = 20;
								break;
						}

					}
				}	//emptyCity while loop


					//returns bool to see if chosen city is adjacent to the cities in checkCity
					/*for (int i = 0; i < numCities; i++) {
					if (graph.IsCityAdjacentToOtherCity(chosenCity, checkCity[i].getCityName())) {
					cout << chosenCity << " is adjacent to your city " << checkCity[i].getCityName() << "." << endl;
					break;
					}
					else {
					continue;
					}
					}*/
				bool cityBought = false;
				int price = 0;
				while (!graph.IsCityAdjacentToOtherCity(chosenCity, checkCity[i].getCityName())) {
					cout << "The city you have chosen is not adjacent to any of your other cities. Please choose another city: " << endl;
					cin >> chosenCity;
					for (int i = 0; i < numCities; i++) {
						if (graph.IsCityAdjacentToOtherCity(chosenCity, checkCity[i].getCityName()) == true) {
							cout << chosenCity << " is adjacent to your city " << checkCity[i].getCityName() << "." << endl;
							price = graph.CostFromOneCityToAnother(checkCity[i].getCityName(), chosenCity);

							cityBought = true;
							break;
						}
						else {
							continue;
						}
					}
				}

				if (cityBought) {
					int total = 0;
					cout << "The connection between the two cities costs " << price << endl;
					cout << "The cost of the city is " << cityPrice << endl;
					cout << "The total cost is " << total << endl;
					cout << "You have bought " << chosenCity << endl;

				}


				//check costs of city plus edges

			}	//citiesOned is > 0




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
				cout << "Your turn is over. It is " << players[i + 1]->getName() << "'s turn next!" << endl;
				stillBuilding = false;
				goto endhere;
			}


		} //stillBuilding while loop
	endhere:continue;
	}	//player loop

		//}	// phase 3 if conditional statement

		//gameIsNotFinished = false;

		//}	//GameisNotFinished while loop

		//deleteDeck(deck);




		//keep console open
	cin.get();

	return 0;
}


