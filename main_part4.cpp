
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

static void shuffle(vector<GameCard*> &_deck)

{
  
    random_shuffle(_deck.begin(),_deck.end());
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

		std::cout << "Initial player order: " << endl;
		std::cout << endl;

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(playerOrder[i]);
		}

		//sort the order of the vertex
		std::sort(players.begin(), players.end(), Player::compByOrder);
		for (int i = 0; i < players.size(); i++) {
			std::cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}

		std::cout << endl;
	}

	else {
		std::cout << "Current player order: " << endl;
		std::cout << endl;

		//sort players by the number of cities they have (for the rest of the game)
		std::sort(players.begin(), players.end(), Player::compByCities);

		for (int i = 0; i < players.size(); i++) {
			players.at(i)->setplayerOrder(i);
		}

		for (int i = 0; i < players.size(); i++) {
			std::cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
		}
		std::cout << endl;
	}
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
    for (int i = 0; i < _deck.size() ; i++)
    {
        _deck[i]->toString();
    }
}

static void deleteDeck(vector<GameCard*> &_deck)
{
    for (int i = 0; i < _deck.size() ; i++)
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
    if(_num==0) return 10;
    else if(_num==1) return 22;
    else if(_num==2) return 33;
    else if(_num==3) return 44;
    else if(_num==4) return 54;
    else if(_num==5) return 64;
    else if(_num==6) return 73;
    else if(_num==7) return 82;
    else if(_num==8) return 90;
    else if(_num==9) return 98;
    else if(_num==10) return 105;
    else if(_num==11) return 112;
    else if(_num==12) return 118;
    else if(_num==13) return 124;
    else if(_num==14) return 129;
    else if(_num==15) return 134;
    else if(_num==16) return 138;
    else if(_num==17) return 142;
    else if(_num==18) return 145;
    else if(_num==19) return 148;
    else if(_num==20) return 150;
    return 0;
}

int main() {

   

	GraphBuilder graph = GraphBuilder(42, "germany.map");


	//========================================TASK 4===================================================
   //BUREAUCRACY
    vector<Player*> players;
    Market *market = new Market(players);
    vector<GameCard*> deck;
    vector<GameCard*> powerPlantMarket;
    makingDeck(deck, powerPlantMarket);
    int numCitiesPowered = 0;
    //number of type bills
    int bill1=0;
    int bill10=0;
    int bill50=0;
    //profit the players gets when powering a certain number of cities
    int profit=0;
    
	//user input
    string choice;
    int round = 1;
 
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
      
		PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
		PowerPlant *p2 = new PowerPlant(4, 1, 2, 0, 0, 0);
		//PowerPlant *p3 = new PowerPlant(5, 1, 2, 2, 0, 0);
	
		market->updateSupply();
		market->toString();
		market->rtPurchase("oil", 2);
		market->rtPurchase("coal", 2);
		market->toString();
		players[0]->addPowerPlant(p1);
		players[0]->addPowerPlant(p2);
		
		p1->stockRT("oil", 2);
		p2->stockRT("coal", 2);
		
		std::cout << "================" << endl;
		std::cout << "BUREAUCRACY" << endl;
		std::cout << "================" << endl;
    
       // DeterminePlayerOrder(players, round);
    
    //iterating through players
        for (int i = 0; i < players.size(); i++) {
            
           vector<PowerPlant*> powerPlantsTEMP;
		   std::cout << "Your turn " + players[i]->getName() + "!" << endl;
		   players[i]->toString();
		   
            powerPlantsTEMP = players[i]->getPowerPlant();
            
            //iterating through powerplants
			cout << "size of power plant vector" <<  players[i]->getPowerPlant().size() << endl;
            for(int i = 0 ; i < powerPlantsTEMP.size(); i++ )
            {
				std::cout << "================" << endl;
				std::cout << "Iterating through owned power plants" << endl;
				std::cout << "================" << endl;
                powerPlantsTEMP[i]->toString();
                
				std::cout << "Would you like to power " << powerPlantsTEMP[i]->getCitiesPowered() << " with this powerplant? yes or no" << endl;
                
                cin >> choice;
                bool valid = false;
                if(choice == "yes")
                {
					std::cout << "With which resource?" << endl;
                    while(!valid)
                    {
                        cin >> choice;
                      if(choice == "coal"|| choice == "oil" || choice == "garbage"|| choice == "uranium")
                      {
						  if (powerPlantsTEMP[i]->checkIfEnoughStock(choice) && powerPlantsTEMP[i]->checkIfNeeded(choice))
						  {
							  powerPlantsTEMP[i]->powerCity(choice);
							  market->addToSupply(choice, powerPlantsTEMP[i]->getRTNeeded(choice));
							  
							
							  market->toString();
							  valid = true;
						  }
						  else
						  {
							  //std::cout << "Not enough in stock!! OR This resource isn't needed for this powerplant" << endl;
						  std::cout << "Enter a valid input please." << endl;
						  valid = false;
						  }

                       
                        
                      }
                      else
                        {
						  std::cout << "Enter a valid input please." << endl;
                        valid = false;
                        }
                    }
                  
                   
                }
                else
                {
					std::cout << "Next Power Plant: " << endl;
					std::cout  << endl;
					std::cout  << endl;
                }
                
				numCitiesPowered+=powerPlantsTEMP[i]->get_numCitiesPowered_ACTIVE();
				//can only power the number of cities they own MAX, otherwise waisted energy
				
				vector<City> temp = players[i]->getCitiesOwned();
			
				if (numCitiesPowered > temp.size())
				{
					numCitiesPowered = temp.size();
				}
            }
            
            
			std::cout << "By powering " << numCitiesPowered << " cities, you earn: " << checkProfit(numCitiesPowered) << endl;
           
            profit = checkProfit(numCitiesPowered);
			std::cout << "================" << endl;
			std::cout << "Initial Wallet: " << endl;
			std::cout << "================" << endl;
			players[i]->walletToString();
            bill50 = (profit - profit%50)/50;
            profit-=bill50*50;
            bill10 = (profit - profit%10)/10;
            profit-=bill10*10;
            bill1 = profit;
            players[i]->collectElektro(bill1,bill10, bill50);
            
			std::cout << "================" << endl;
			std::cout << "Updated Wallet: " << endl;
			std::cout << "================" << endl;
		
			players[i]->walletToString();

			players[i]->toString();
        }
    
    int step = 1;
    //removing most expensive Power plant from the market and placing it under the draw deck
    GameCard *MostExpensive = powerPlantMarket.at(powerPlantMarket.size()-1);
    powerPlantMarket.pop_back();
    deck.push_back(MostExpensive);
    
    //drawing new card from deck and adding it the power plant market
    GameCard *newCard = deck.at(0);
    deck.erase(deck.begin());
    powerPlantMarket.push_back(newCard);
    //placing the cards in ascending order of price
    sortMarket(powerPlantMarket);
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
	std::cout << "PRINTING DECK" << endl;
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
    
    print(deck);
    
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
	std::cout << "PRINTING POWERPLANT MARKET" << endl;
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
    
    print(powerPlantMarket);
    //restock resource market
    
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
	std::cout << "PRINTING RESOURCE MARKET" << endl;
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
     market->toString();
    market->restockMarket(step);
 
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
	std::cout << "PRINTING RESOURCE MARKET::RESTOCKED" << endl;
	std::cout << "===============" << endl;
	std::cout << "===============" << endl;
    market->toString();

	delete newCard;
	newCard = NULL;

	delete MostExpensive;
	MostExpensive = NULL;

	delete market;
	market = NULL;

	delete p1;
	p1 = NULL;

	delete p2;
	p2 = NULL;

	for (int i = 0; i < players.size(); i++) {
		delete players[i];
		players[i] = NULL;
	}
	
	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <random>
//#include <ctype.h>
//#include "player.hpp"
//#include "City.h"
//#include "GraphBuilder.h"
//#include "Elektro.hpp"
//#include "Market.hpp"
//#include "HelperFunctions.hpp"
////
//using namespace std;
//using namespace HelperFunctions;
//
//static void shuffle(vector<GameCard*> &_deck)
//
//{
//  
//    random_shuffle(_deck.begin(),_deck.end());
//}
//
//
//
//static void DeterminePlayerOrder(vector<Player*> &players, int round) {
//
//	vector<int> playerOrder;
//
//	if (round == 1) {
//		for (int i = 0; i < players.size(); i++) {
//			playerOrder.push_back(i);
//		}
//
//		//give random turn to each player
//		std::random_device rd;
//		std::mt19937 g(rd());
//		std::shuffle(playerOrder.begin(), playerOrder.end(), g);
//
//		std::cout << "Initial player order: " << endl;
//		std::cout << endl;
//
//		for (int i = 0; i < players.size(); i++) {
//			players.at(i)->setplayerOrder(playerOrder[i]);
//		}
//
//		//sort the order of the vertex
//		std::sort(players.begin(), players.end(), Player::compByOrder);
//		for (int i = 0; i < players.size(); i++) {
//			std::cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
//		}
//
//		std::cout << endl;
//	}
//
//	else {
//		std::cout << "Current player order: " << endl;
//		std::cout << endl;
//
//		//sort players by the number of cities they have (for the rest of the game)
//		std::sort(players.begin(), players.end(), Player::compByCities);
//
//		for (int i = 0; i < players.size(); i++) {
//			players.at(i)->setplayerOrder(i);
//		}
//
//		for (int i = 0; i < players.size(); i++) {
//			std::cout << "Player: " << players.at(i)->getName() << ", Turn: " << players.at(i)->getplayerOrder() << endl;
//		}
//		std::cout << endl;
//	}
//}
//
//static void makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket)
//{
//
//    //  PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed);
//    
//    PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
//    PowerPlant *p2 = new PowerPlant(4, 1, 2, 0, 0, 0);
//    PowerPlant *p3 = new PowerPlant(5, 1, 2, 2, 0, 0);
//    PowerPlant *p4 = new PowerPlant(6, 1, 0, 0, 1, 0);
//    PowerPlant *p5 = new PowerPlant(7, 2, 0, 3, 0, 0);
//    PowerPlant *p6 = new PowerPlant(8, 2, 3, 0, 0, 0);
//    PowerPlant *p7 = new PowerPlant(9, 1, 0, 1, 0, 0);
//    PowerPlant *p8 = new PowerPlant(10, 2, 2, 0, 0, 0);
//    PowerPlant *p9 = new PowerPlant(11, 2, 0, 0, 0, 1);
//    PowerPlant *p10 = new PowerPlant(12, 2, 2, 2, 0, 0);
//    PowerPlant *p11 = new PowerPlant(13, 1, 0, 0, 0, 0);
//    PowerPlant *p12 = new PowerPlant(14, 2, 0, 0, 2, 0);
//    PowerPlant *p13 = new PowerPlant(15, 3, 2, 0, 0, 0);
//    PowerPlant *p14 = new PowerPlant(16, 3, 0, 2, 0, 0);
//    PowerPlant *p15 = new PowerPlant(17, 2, 0, 0, 0, 1);
//    PowerPlant *p16 = new PowerPlant(18, 2, 0, 0, 0, 0);
//    PowerPlant *p17 = new PowerPlant(19, 3, 0, 0, 2, 0);
//    PowerPlant *p18 = new PowerPlant(20, 5, 3, 0, 0, 0);
//    PowerPlant *p19 = new PowerPlant(21, 4, 2, 2, 0, 0);
//    PowerPlant *p20 = new PowerPlant(22, 2, 0, 0, 0, 0);
//    PowerPlant *p21 = new PowerPlant(23, 3, 0, 0, 0, 1);
//    PowerPlant *p22 = new PowerPlant(24, 4, 0, 0, 2, 0);
//    PowerPlant *p23 = new PowerPlant(25, 5, 2, 0, 0, 0);
//    PowerPlant *p24 = new PowerPlant(26, 5, 0, 2, 0, 0);
//    PowerPlant *p25 = new PowerPlant(27, 3, 0, 0, 0, 0);
//    PowerPlant *p26 = new PowerPlant(28, 4, 0, 0, 0, 1);
//    PowerPlant *p27 = new PowerPlant(29, 4, 2, 2, 0, 0);
//    PowerPlant *p28 = new PowerPlant(30, 6, 0, 0, 3, 0);
//    PowerPlant *p29 = new PowerPlant(31, 6, 3, 0, 0, 0);
//    PowerPlant *p30 = new PowerPlant(32, 6, 0, 3, 0, 0);
//    PowerPlant *p31 = new PowerPlant(33, 4, 0, 0, 0, 0);
//    PowerPlant *p32 = new PowerPlant(34, 5, 0, 0, 0, 1);
//    PowerPlant *p33 = new PowerPlant(35, 5, 0, 1, 0, 0);
//    PowerPlant *p34 = new PowerPlant(36, 7, 3, 0, 0, 0);
//    PowerPlant *p35 = new PowerPlant(37, 4, 0, 0, 0, 0);
//    PowerPlant *p36 = new PowerPlant(38, 7, 0, 0, 3, 0);
//    PowerPlant *p37 = new PowerPlant(39, 6, 0, 0, 0, 1);
//    PowerPlant *p38 = new PowerPlant(40, 6, 0, 2, 0, 0);
//    PowerPlant *p39 = new PowerPlant(42, 6, 2, 0, 0, 0);
//    PowerPlant *p40 = new PowerPlant(44, 5, 0, 0, 0, 0);
//    PowerPlant *p41 = new PowerPlant(46, 7, 3, 3, 0, 0);
//    PowerPlant *p42 = new PowerPlant(50, 6, 0, 0, 0, 0);
//    
//    
//    GameCard *s3 = new GameCard("s3");
//    
//    
//    //SETTING UP THE POWERPLANT MARKET
//    _powerPlantMarket.push_back(p1);
//    _powerPlantMarket.push_back(p2);
//    _powerPlantMarket.push_back(p3);
//    _powerPlantMarket.push_back(p4);
//    _powerPlantMarket.push_back(p5);
//    _powerPlantMarket.push_back(p6);
//    _powerPlantMarket.push_back(p7);
//    
//    
//    //making the rest of the deck, ready to shuffle
//    _deck.push_back(p9);
//    _deck.push_back(p10);
//    //_deck.push_back(p11);
//    _deck.push_back(p12);
//    _deck.push_back(p13);
//    _deck.push_back(p14);
//    _deck.push_back(p15);
//    _deck.push_back(p16);
//    _deck.push_back(p17);
//    _deck.push_back(p18);
//    _deck.push_back(p19);
//    _deck.push_back(p20);
//    _deck.push_back(p21);
//    _deck.push_back(p22);
//    _deck.push_back(p23);
//    _deck.push_back(p24);
//    _deck.push_back(p25);
//    _deck.push_back(p26);
//    _deck.push_back(p27);
//    _deck.push_back(p28);
//    _deck.push_back(p29);
//    _deck.push_back(p30);
//    _deck.push_back(p31);
//    _deck.push_back(p32);
//    _deck.push_back(p33);
//    _deck.push_back(p34);
//    _deck.push_back(p35);
//    _deck.push_back(p36);
//    _deck.push_back(p37);
//    _deck.push_back(p38);
//    _deck.push_back(p39);
//    _deck.push_back(p40);
//    _deck.push_back(p41);
//    _deck.push_back(p42);
//    
//    //following game rules:
//    //top of deck: powerplant 13
//    //bottom: step3 card
//    shuffle(_deck);
//    //random_shuffle(_deck.begin(),_deck.end());
//    _deck.push_back(s3);
//    _deck.insert(_deck.begin(), p11);
//}
//
//static void print(vector<GameCard*> &_deck)
//{
//    for (int i = 0; i < _deck.size() ; i++)
//    {
//        _deck[i]->toString();
//    }
//}
//
//static void deleteDeck(vector<GameCard*> &_deck)
//{
//    for (int i = 0; i < _deck.size() ; i++)
//    {
//        
//        delete _deck[i];
//        _deck[i] = NULL;
//    }
//    
//}
//
//static void sortMarket(vector<GameCard*> &_powerPlantMarket)
//{
//    sort(_powerPlantMarket.begin(), _powerPlantMarket.end());
//    
//}
//static int checkProfit(int _num)
//{
//    if(_num==0) return 10;
//    else if(_num==1) return 22;
//    else if(_num==2) return 33;
//    else if(_num==3) return 44;
//    else if(_num==4) return 54;
//    else if(_num==5) return 64;
//    else if(_num==6) return 73;
//    else if(_num==7) return 82;
//    else if(_num==8) return 90;
//    else if(_num==9) return 98;
//    else if(_num==10) return 105;
//    else if(_num==11) return 112;
//    else if(_num==12) return 118;
//    else if(_num==13) return 124;
//    else if(_num==14) return 129;
//    else if(_num==15) return 134;
//    else if(_num==16) return 138;
//    else if(_num==17) return 142;
//    else if(_num==18) return 145;
//    else if(_num==19) return 148;
//    else if(_num==20) return 150;
//    return 0;
//}
//
//int main() {
//
//   
//
//	GraphBuilder graph = GraphBuilder(42, "germany.map");
//
//
//	//========================================TASK 4===================================================
//   //BUREAUCRACY
//    vector<Player*> players;
//    Market *market = new Market(players);
//    vector<GameCard*> deck;
//    vector<GameCard*> powerPlantMarket;
//    makingDeck(deck, powerPlantMarket);
//    int numCitiesPowered = 0;
//    //number of type bills
//    int bill1=0;
//    int bill10=0;
//    int bill50=0;
//    //profit the players gets when powering a certain number of cities
//    int profit=0;
//    
//	//user input
//    string choice;
//    int round = 1;
// 
//        players.push_back(new Player("Nicole", "Red"));
//        players.push_back(new Player("Voldermort", "Green"));
//        players.push_back(new Player("Pikachu", "Blue"));
//        players.push_back(new Player("Smith", "Purple"));
//      
//		graph.add_CityToPlayer_and_PlayerToMap(players[0], "Berlin");
//		graph.add_CityToPlayer_and_PlayerToMap(players[0], "Frankfurt-O");
//		graph.add_CityToPlayer_and_PlayerToMap(players[1], "Kiel");
//		graph.add_CityToPlayer_and_PlayerToMap(players[2], "Frankfurt-M");
//		graph.add_CityToPlayer_and_PlayerToMap(players[2], "Hamburg");
//		graph.add_CityToPlayer_and_PlayerToMap(players[2], "Cuxhaven");
//      
//		PowerPlant *p1 = new PowerPlant(3, 1, 0, 2, 0, 0);
//		PowerPlant *p2 = new PowerPlant(4, 1, 2, 0, 0, 0);
//		//PowerPlant *p3 = new PowerPlant(5, 1, 2, 2, 0, 0);
//		p1->stockRT("oil", 2);
//		p2->stockRT("coal", 2);
//		market->updateSupply();
//		market->toString();
//		market->rtPurchase("oil", 2);
//		market->rtPurchase("coal", 2);
//		market->toString();
//		players[0]->addPowerPlant(*p1);
//		players[0]->addPowerPlant(*p2);
//		
//		
//		
//		std::cout << "================" << endl;
//		std::cout << "BUREAUCRACY" << endl;
//		std::cout << "================" << endl;
//    
//       // DeterminePlayerOrder(players, round);
//    
//    //iterating through players
//        for (int i = 0; i < players.size(); i++) {
//            
//           vector<PowerPlant> powerPlantsTEMP;
//		   std::cout << "Your turn " + players[i]->getName() + "!" << endl;
//		   players[i]->toString();
//		   
//            powerPlantsTEMP = players[i]->getPowerPlant();
//            
//            //iterating through powerplants
//			cout << "size of power plant vector" <<  players[i]->getPowerPlant().size() << endl;
//            for(int i = 0 ; i < powerPlantsTEMP.size(); i++ )
//            {
//				std::cout << "================" << endl;
//				std::cout << "Iterating through owned power plants" << endl;
//				std::cout << "================" << endl;
//                powerPlantsTEMP[i].toString();
//                
//				std::cout << "Would you like to power " << powerPlantsTEMP[i].getCitiesPowered() << " with this powerplant? yes or no" << endl;
//                
//                cin >> choice;
//                bool valid = false;
//                if(choice == "yes")
//                {
//					std::cout << "With which resource?" << endl;
//                    while(!valid)
//                    {
//                        cin >> choice;
//                      if(choice == "coal"|| choice == "oil" || choice == "garbage"|| choice == "uranium")
//                      {
//						  if (powerPlantsTEMP[i].checkIfEnoughStock(choice) && powerPlantsTEMP[i].checkIfNeeded(choice))
//						  {
//							  powerPlantsTEMP[i].powerCity(choice);
//							  market->addToSupply(choice, powerPlantsTEMP[i].getRTNeeded(choice));
//							  
//							
//							  market->toString();
//							  valid = true;
//						  }
//						  else
//						  {
//							  //std::cout << "Not enough in stock!! OR This resource isn't needed for this powerplant" << endl;
//						  std::cout << "Enter a valid input please." << endl;
//						  valid = false;
//						  }
//
//                       
//                        
//                      }
//                      else
//                        {
//						  std::cout << "Enter a valid input please." << endl;
//                        valid = false;
//                        }
//                    }
//                  
//                   
//                }
//                else
//                {
//					std::cout << "Next Power Plant: " << endl;
//					std::cout  << endl;
//					std::cout  << endl;
//                }
//                
//				numCitiesPowered+=powerPlantsTEMP[i].get_numCitiesPowered_ACTIVE();
//				//can only power the number of cities they own MAX, otherwise waisted energy
//				
//				vector<City> temp = players[i]->getCitiesOwned();
//			
//				if (numCitiesPowered > temp.size())
//				{
//					numCitiesPowered = temp.size();
//				}
//            }
//            
//            
//			std::cout << "By powering " << numCitiesPowered << " cities, you earn: " << checkProfit(numCitiesPowered) << endl;
//           
//            profit = checkProfit(numCitiesPowered);
//			std::cout << "================" << endl;
//			std::cout << "Initial Wallet: " << endl;
//			std::cout << "================" << endl;
//			players[i]->walletToString();
//            bill50 = (profit - profit%50)/50;
//            profit-=bill50*50;
//            bill10 = (profit - profit%10)/10;
//            profit-=bill10*10;
//            bill1 = profit;
//            players[i]->collectElektro(bill1,bill10, bill50);
//            
//			std::cout << "================" << endl;
//			std::cout << "Updated Wallet: " << endl;
//			std::cout << "================" << endl;
//		
//			players[i]->walletToString();
//
//			players[i]->toString();
//        }
//    
//    int step = 1;
//    //removing most expensive Power plant from the market and placing it under the draw deck
//    GameCard *MostExpensive = powerPlantMarket.at(powerPlantMarket.size()-1);
//    powerPlantMarket.pop_back();
//    deck.push_back(MostExpensive);
//    
//    //drawing new card from deck and adding it the power plant market
//    GameCard *newCard = deck.at(0);
//    deck.erase(deck.begin());
//    powerPlantMarket.push_back(newCard);
//    //placing the cards in ascending order of price
//    sortMarket(powerPlantMarket);
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "PRINTING DECK" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//    
//    print(deck);
//    
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "PRINTING POWERPLANT MARKET" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//    
//    print(powerPlantMarket);
//    //restock resource market
//    
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "PRINTING RESOURCE MARKET" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//     market->toString();
//    market->restockMarket(step);
// 
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "PRINTING RESOURCE MARKET::RESTOCKED" << endl;
//	std::cout << "===============" << endl;
//	std::cout << "===============" << endl;
//    market->toString();
//
//	delete newCard;
//	newCard = NULL;
//
//	delete MostExpensive;
//	MostExpensive = NULL;
//
//	delete market;
//	market = NULL;
//
//	delete p1;
//	p1 = NULL;
//
//	delete p2;
//	p2 = NULL;
//
//	for (int i = 0; i < players.size(); i++) {
//		delete players[i];
//		players[i] = NULL;
//	}
//	
//	return 0;
//}
//

