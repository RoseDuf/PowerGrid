#ifndef Market_hpp
#define Market_hpp


#include <stdio.h>
#include <string>
#include <iostream>
#include "player.hpp"
#include <vector>
using namespace std;

class Market
{

private:

	//total resource token pieces in the game
	static const int TOTAL_COAL = 24;
	static const int TOTAL_OIL = 24;
	static const int TOTAL_GARBAGE = 24;
	static const int TOTAL_URANIUM = 12;

	//current tokens on the board in the market section
	int coal_market = 0;
	int oil_market = 0;
	int garbage_market = 0;
	int uranium_market = 0;

	//prices of the tokens according to how many is in the market
	int coal_price = 0;
	int oil_price = 0;
	int garbage_price = 0;
	int uranium_price = 0;

	//available tokens
	int coal_supply = 0;
	int oil_supply = 0;
	int garbage_supply = 0;
	int uranium_supply = 0;

	vector<Player*> players;
public:

	Market(vector<Player*> &_players);
	Market();
	//setting up maket
	// Market(int coal, int oil, int garbage, int uranium, vector<Player*> &_players);
	~Market();

	void restockMarket(int step);
	void rtPurchase(string type, int number);
	bool checkMarket(string type, int number);
	bool checkSupply(string type, int number);
	int getPrice(string type);
	void display();
	void updateSupply();
	void addToSupply(string type, int number);

	void toString();
};
#endif /* Market_hpp */
