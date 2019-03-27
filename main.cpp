/*

//  main.cpp
//  player
//  Driver class for Player object
//change..

#include <iostream>
#include "player.hpp"
#include "City.h"
//#include "GraphBuilder.h"

#include "HelperFunctions.hpp"
#include <algorithm>
#include "Market.hpp"

using namespace std;
using namespace HelperFunctions;

/*
 I placed this within the making deck method for testing
 Will implement in a class after testing
  */
static void shuffle(vector<GameCard*> &_deck)

{
    cout << "===============" << endl;
     cout << "===============" << endl;
    cout << "SHUFFLED" << endl;
    cout << "===============" << endl;
    cout << "===============" << endl;
   
    random_shuffle(_deck.begin(),_deck.end());
}
 
static void makingDeck(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket)
{
    //_deck = &deck;
    ///
    //GameCard p1 =    GameCard("Here");
    
    //now it is a pointer to a PowerPlant object, now a true pointer
    //without the new, we were staying in the stack, the child part was local, with new , the child part goes into the heap and isn,t lost.
    
    //before it is was just an object,
    
    
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

static void bureaucracy(vector<GameCard*> &_deck, vector<GameCard*> &_powerPlantMarket, Market &_market, int _step, vector<Player*> &_players)
{
        cout << "================" << endl;
    cout << "BUREAYCRACY" << endl;
        cout << "================" << endl;
    //RN i made several methods in the main, to test things out, but I think I will be making classes to
    //better implement this
    
    //NEED TO SEE WHEN IN THE GAME: REMOVING 1st and last power plant in step ## ?
    
    //removing most expensive Power plant from the market and placing it under the draw deck
    GameCard *MostExpensive = _powerPlantMarket.at(_powerPlantMarket.size()-1);
    _powerPlantMarket.pop_back();
    _deck.push_back(MostExpensive);
    
    //drawing new card from deck and adding it the power plant market
    GameCard *newCard = _deck.at(0);
    _deck.erase(_deck.begin());
    _powerPlantMarket.push_back(newCard);
    //placing the cards in ascending order of price
    sortMarket(_powerPlantMarket);
    
    int numCitiesPowered = 0;
    //number of type bills
    int bill1=0;
    int bill10=0;
    int bill50=0;
    //profit the players gets when powering a certain number of cities
    int profit=0;
    
    //each player collects cash according to cities powered
    for(int i = 0; i < _players.size(); i++)
    {
        //***need a method to determine the number of cities powered
        numCitiesPowered = _players[i]->getCitiesPowered();
        profit = checkProfit(numCitiesPowered);
        
        bill50 = (profit - profit%50)/50;
        profit-=bill50*50;
        bill10 = (profit - profit%10)/10;
        profit-=bill10*10;
        bill1 = profit;
        _players[i]->collectElektro(bill1,bill10, bill50);
    }
    //restock resource market
   _market.restockMarket(_step);
    
   
}


int main() {
    
    static vector<GameCard*> deck;
    static vector<Player*> players;
    static vector<GameCard*> powerPlantMarket;
    
    
    Market *market = new Market(players);
    
    makingDeck(deck, powerPlantMarket);
    
   //print(powerPlantMarket);
    
    int step = 1;
    
    market->toString();
    bureaucracy(deck, powerPlantMarket, *market, step, players);
    market->toString();

  
    PowerPlant *test = new PowerPlant(50, 6, 1, 0, 0, 0);
    
    
    //some track with supply and market isn't working ***
      cout<< "a player bought coal " << endl;
    test->stockRT("coal", 1);
    market->rtPurchase("coal", 1);
     market->toString();
      cout<< "a player is powering a city " << endl;
    test->powerCity("coal");
    market->addToSupply("coal", 1);
     market->toString();
}
*/
