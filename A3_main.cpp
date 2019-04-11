
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Game.h"


using namespace std;
using namespace HelperFunctions;


int main()
{
	
	Game test;
	test.deckSetup();
	test.setUpPlayers();
	test.setUpMap();
	test.phase1_determinePlayerOrder();
	test.phase2_auction();
	test.phase3_buyingResources();
	test.phase4_building();
	test.phase5_bureaucracy();


	return 0;
}

