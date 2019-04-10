
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include "Game.h"


using namespace std;
//using namespace HelperFunctions;


int main()
{


	Game test;
	test.phase1_determinePlayerOrder();
	test.phase2_auction();

	return 0;
}