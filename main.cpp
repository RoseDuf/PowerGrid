//main for task 3

#include "Game.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "player.hpp"
#include "Market.hpp"

using namespace std;

//playerOrder must be available to all of Driver
/*static vector<Player*> playerOrder;

static void DeterminePlayerOrder(vector<Player*> players, int round) {

	if (round == 1) {
		for (int i = 0; i < players.size(); i++) {
			playerOrder.push_back(players[i]);
		}

		//give random turn to each player
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(playerOrder.begin(), playerOrder.end(), g);

		cout << "Initial player order: " << endl;
		cout << endl;

		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << playerOrder[i] -> getName() << ", Turn: " << (i+1) << endl;
		}
		cout << endl;
	}

	else if (round == 2 || round == 3) {
		//reverse vector order
		reverse(playerOrder.begin(), playerOrder.end());

		cout << "Current player order:\n" << endl;

		for (int i = 0; i < players.size(); i++) {
			cout << "Player: " << playerOrder[i]->getName() << ", Turn: " << (i + 1) << endl;
		}
		cout << endl;
	}

	/*else {
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
	}}*/





int main() {

	vector <Player*> players{};
	players.push_back(new Player("Nicole", "red"));
	players.push_back(new Player("Voldermort", "Green"));
	players.push_back(new Player("Pikachu", "Blue"));
	players.push_back(new Player("Smith", "Purple"));


	Game game1(players);


	Market m1 = Market();

	PowerPlant test1(2, 2, 3, 2, 0, 0);

	vector<PowerPlant> p1vect{};

	Player* p1 = players[0];

	p1vect.push_back(test1);
	p1->setPowerPlant(p1vect);

	/* //this works//
	vector <PowerPlant> show = p1.getPowerPlant();

	for (int i =0; i < show.size(); i++) {
		show[i].toString();
	}*/

	game1.dashboard(p1);


	//TASK 3 --- BUYING RESOURCES --- //

	bool gameIsNotFinished = true;
	int round = 2;

	while (gameIsNotFinished) {

		if (round == 2) {

			//call method to reverse player order ***Use std::sort***
			//DeterminePlayerOrder(players, round);

			//for (int i = 0; i < playerOrder.size(); i++) {
				//cout << "Your turn " + playerOrder[i]->getName() << endl;

				//display Resource Market
			m1.display();

			//make this better in future by creating an exception that catches this...
			//vector <PowerPlant> temp = playerOrder[i]->getPowerPlant();
			//if ( temp.size() == 0) {
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
					//}

					cout << "You chose " << resource << endl;

					//check if resources match ones on Player's powerplants
					//for (int i = 0; i < temp.size(); i++) {
						//isMatch = temp[i].checkIfNeeded(resource);
					if (isMatch) {
						break;
						//}
					//}

						cout << "Sorry you cannot buy this resource because you do not have a corresponding resource in your PowerPlants." << endl;
					}

					//check if player can afford resource
					//if (m1.getPrice(resource) <= playerOrder[i]->getTotalWallet()) {
					cout << "Sorry you do not have enough Elektros to buy the resource." << endl;
				}
				//else {
					//check ResourceMarket price for resource
				cout << "You paid " + m1.getPrice(resource) << " Elektros for " + resource << "." << endl;

				//****HOW TO calculate THIS!!***** remove Elektros from player object

				/*playerOrder[i].spendElektros(int, int, int)*/

				//add resource to player object

				//}
		//}
	//}

			}
		}



		//keep console open
		cin.get();

	}

}