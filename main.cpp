//  main.cpp
//  player
//  Driver class for Player object
//change..

#include <iostream>
#include "player.hpp"
#include "City.h"
#include "GraphBuilder.h"

#include "HelperFunctions.hpp"
#include <algorithm>

using namespace std;
using namespace HelperFunctions;


static void shuffle(vector<GameCard*> &_deck)
{
    cout << "===============" << endl;
     cout << "===============" << endl;
    cout << "SHUFFLED" << endl;
    cout << "===============" << endl;
    cout << "===============" << endl;
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
    
    std::cout << "true = " << true << std::endl; // just to emphasize that true = 1
    
    // Select a map
    std::cout << "Choose one of the following maps (by entering the appropriate number).:" << std::endl;
    std::cout << "1) Germany map" << std::endl;
    std::cout << "2) USA map" << std::endl;
    
    int mapChoice;
    
    std::cin >> mapChoice;
    
    std::string mapFilename;
    if(mapChoice == 1) {
        mapFilename = "germany.map";
    }
    else if(mapChoice == 2) {
        mapFilename = "usa.map"; // TODO
    }
    /*else {
        throw no map exception or something like that
    }//*/
    
    MapData mapData = PowerGridIO::getMapData(mapFilename);
    std::vector<AdjacentRegionsTriplet> arts = std::get<2>(mapData);
    vector<string> chosenRegCols;
    /*without_user_input_version:chosenRegCols.push_back("RED");
    chosenRegCols.push_back("ORANGE");
    chosenRegCols.push_back("GREEN");
    chosenRegCols.push_back("PURPLE");
    //chosenRegCols.push_back("YELLOW");//
    //chosenRegCols.push_back("BLUE");//*/
    
        // Select the number of players in the game
    std::cout << "How many players? (2-6):";
    int amountOfPlayers = 0;
    std::cin >> amountOfPlayers;
    for(int i = 0; i < amountOfPlayers; i++) {
        
        std::cout << "Choose region color " << (i+1) << ":";
        std::string currentRegionColorChoice = "";
        std::cin >> currentRegionColorChoice;
        chosenRegCols.push_back(currentRegionColorChoice);
    }
    
    int amountOfVertices = std::get<0>(mapData).size(); // amountOfVertices = amount of cities
    GraphBuilder graph = GraphBuilder( amountOfVertices, mapFilename );
	//graph.buildMap(); //DON'T FORGET TO BUILD MAP !! // I PUT IT IN THE CONSTRUCTOR NOW.

    std::cout << "are chosen regions connected?: " << graph.areChosenRegionsConnected(chosenRegCols) << std::endl;
    std::cout << "do all regions have exactly 7 cities?:" << graph.eachRegionHasSevenCities() << std::endl;
	std::cout << "is connected graph?:" << graph.test_MissingEdges() << std::endl;
	std::cout << "does map have duplicate edges?:" << graph.test_Duplicate_Edges() << std::endl;

	/*
    static vector<GameCard*> deck;
    
    makingDeck(deck);
    //printDeck(deck);
    shuffle(deck);
   // printDeck(deck);
    cout << deck.size() << endl;
    deleteDeck(deck);
    PowerPlant *test = new PowerPlant(66, 6, 1, 0, 0, 0);
    test->toString();
    test->stockRT("coal", 2);
     test->toString();
    test->powerCity("coal");
     test->toString();
    delete test;
    test= NULL;
    //*/
    return 0;
}

/*#include "PowerGridIO.hpp"

int main(void) {
 
    
    //GameState gameState = PowerGridIO::loadGame("file.save");
    MapData mapData = PowerGridIO::getMapData("file.map");
    return 0;
}*/
