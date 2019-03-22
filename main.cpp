//  main.cpp
//  player
//  Driver class for Player object
//change..

#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"

using namespace std;
using namespace HelperFunctions;


static void shuffle(vector<GameCard*> &_deck)
{
    cout << "SHUFFLED" << endl;
    random_shuffle(_deck.begin(),_deck.end());
}
static void makingDeck(vector<GameCard*> &_deck)
{
    //_deck = &deck;
    ///
    //GameCard p1 =    GameCard("Here");
    
    //now it is a pointer to a PowerPlant object, now a true pointer
    //without the new, we were staying in the stack, the child part was local, with new , the child part goes into the heap and isn,t lost.
    
    //before it is was just an object,
    
    PowerPlant *p1 = new PowerPlant(3, 1, 2, "oil", "");
    PowerPlant *p2 = new PowerPlant(4, 1, 2, "coal", "");
    PowerPlant *p3 = new PowerPlant(5, 1, 2, "coal", "oil");
    PowerPlant *p4 = new PowerPlant(6, 1, 1, "garbage", "" );
    PowerPlant *p5 = new PowerPlant(7, 2, 3, "oil", "");
    PowerPlant *p6 = new PowerPlant(8, 2, 3, "coal", "");
    PowerPlant *p7 = new PowerPlant(9, 1, 1, "oil", "");
    PowerPlant *p8 = new PowerPlant(10, 2, 2, "coal", "");
    PowerPlant *p9 = new PowerPlant(11, 2, 1, "uranium", "");
    PowerPlant *p10 = new PowerPlant(12, 2, 2, "oil", "coal");
    PowerPlant *p11 = new PowerPlant(13, 1, 0, "", "");
    PowerPlant *p12 = new PowerPlant(14, 2, 2, "garbage", "");
    PowerPlant *p13 = new PowerPlant(15, 3, 2, "coal", "");
    PowerPlant *p14 = new PowerPlant(16, 3, 2, "oil", "");
    PowerPlant *p15 = new PowerPlant(17, 2, 1, "uranium", "");
    PowerPlant *p16 = new PowerPlant(18, 2, 0, "", "");
    PowerPlant *p17 = new PowerPlant(19, 3, 2, "garbage", "");
    PowerPlant *p18 = new PowerPlant(20, 5, 3, "coal", "");
    PowerPlant *p19 = new PowerPlant(21, 4, 2, "coal", "oil");
    PowerPlant *p20 = new PowerPlant(22, 2, 0, "", "");
    PowerPlant *p21 = new PowerPlant(23, 3, 1, "uranium", "");
    PowerPlant *p22 = new PowerPlant(24, 4, 2, "garbage", "");
    PowerPlant *p23 = new PowerPlant(25, 5, 2, "coal", "");
    PowerPlant *p24 = new PowerPlant(26, 5, 2, "oil", "");
    PowerPlant *p25 = new PowerPlant(27, 3, 0, "", "");
    PowerPlant *p26 = new PowerPlant(28, 4, 1, "uranium", "");
    PowerPlant *p27 = new PowerPlant(29, 4, 2, "oil", "coal");
    PowerPlant *p28 = new PowerPlant(30, 6, 3, "garbage", "");
    PowerPlant *p29 = new PowerPlant(31, 6, 3, "coal", "");
    PowerPlant *p30 = new PowerPlant(32, 6, 3, "oil", "");
    PowerPlant *p31 = new PowerPlant(33, 4, 0, "", "");
    PowerPlant *p32 = new PowerPlant(34, 5, 1, "uranium", "");
    PowerPlant *p33 = new PowerPlant(35, 5, 1, "oil", "");
    PowerPlant *p34 = new PowerPlant(36, 7, 3, "coal", "");
    PowerPlant *p35 = new PowerPlant(37, 4, 0, "", "");
    PowerPlant *p36 = new PowerPlant(38, 7, 3, "garbage", "");
    PowerPlant *p37 = new PowerPlant(39, 6, 1, "uranium", "");
    PowerPlant *p38 = new PowerPlant(40, 6, 2, "oil", "");
    PowerPlant *p39 = new PowerPlant(42, 6, 2, "coal", "");
    PowerPlant *p40 = new PowerPlant(44, 5, 0, "", "");
    PowerPlant *p41 = new PowerPlant(46, 7, 3, "oil", "coal");
    PowerPlant *p42 = new PowerPlant(50, 6, 0, "", "");
    
    
    GameCard s3 = GameCard("s3");
    
    _deck.push_back(p1);
    _deck.push_back(p2);
    _deck.push_back(p3);
    _deck.push_back(p4);
    _deck.push_back(p5);
    _deck.push_back(p6);
    _deck.push_back(p7);
    _deck.push_back(p8);
    
    
     _deck.push_back(p9);
     _deck.push_back(p10);
     _deck.push_back(p11);
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
    
    
}

static void printDeck(vector<GameCard*> &_deck)
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

int main() {
    
    static vector<GameCard*> deck;
    
    makingDeck(deck);
    printDeck(deck);
    shuffle(deck);
    printDeck(deck);
    cout << deck.size() << endl;


    
}
