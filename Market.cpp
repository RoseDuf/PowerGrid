
#include "Market.hpp"


Market::Market(vector<Player*> &_players)
{
	coal_market = 24;
	oil_market = 15;
	garbage_market = 6;
	uranium_market = 2;
	players = _players;

}

Market::Market()
{

}

Market::~Market()
{

}

//called in PowerPlant class when the player powers a city and consume the resources stocked on power plant card
void Market::addToSupply(string type, int number)
{
	cout << "adding to suplply " << type << number << endl;
	if (type == "coal")
	{
		coal_supply += number;
	}
	else if (type == "oil")
	{
		cout << "oilSupply" << oil_supply << endl;
		oil_supply += number;
		cout << "oilSupply" << oil_supply << endl;
	}

	else if (type == "garbage")
	{
		garbage_supply += number;
	}
	else if (type == "uranium")
	{
		uranium_supply += number;
	}

}

void Market::updateSupply()
{

	int playersCoal = 0;
	int playersOil = 0;
	int playersGarbage = 0;
	int playersUranium = 0;

	for (int i = 0; i < players.size(); i++)
	{
		//NEED A WAY TO GET PLAYERS NUMBER OF RESOURCE TOKEN
		playersCoal += players[i]->getTotalCoal();
		playersOil += players[i]->getTotalOil();
		playersGarbage += players[i]->getTotalGarbage();
		playersUranium += players[i]->getTotalUranium();
	}

	// cout << "players coal: "<< playersCoal << endl;
	//cout << "players oil: "<< playersOil << endl;
	//cout << "players garbage: "<< playersGarbage << endl;
	//cout << "players uranium: "<< playersUranium << endl;
	coal_supply = TOTAL_COAL - coal_market;
	oil_supply = TOTAL_OIL - oil_market;
	garbage_supply = TOTAL_GARBAGE - garbage_market;
	uranium_supply = TOTAL_URANIUM - uranium_market;
}

void Market::restockMarket(int step)
{


	//need to check if enough in supply before restock***
	if (step == 1)
	{
		//checks if there are enough tokens left in  the supply "bag" to restock the  market according
		//to specific step
		//if not, add what is left from the supply
		if (checkSupply("coal", 3))
		{
			coal_market += 3;
			coal_supply -= 3;
		}
		else
		{
			coal_market += coal_supply;
			coal_supply = 0;
		}

		if (checkSupply("oil", 2))
		{
			oil_market += 2;
			oil_supply -= 2;
		}
		else
		{
			oil_market += oil_supply;
			oil_supply = 0;
		}

		if (checkSupply("garbage", 1))
		{
			garbage_market += 1;
			garbage_supply -= 1;
		}
		else
		{
			garbage_market += garbage_supply;
			garbage_supply = 0;
		}
		if (checkSupply("uranium", 1))
		{
			uranium_market += 1;
			uranium_supply -= 1;
		}
		else
		{
			uranium_market += uranium_supply;
			uranium_supply = 0;
		}

	}
	else if (step == 2)
	{
		if (checkSupply("coal", 4))
		{
			coal_market += 4;
			coal_supply -= 4;
		}
		else
		{
			coal_market += coal_supply;
			coal_supply = 0;
		}

		if (checkSupply("oil", 2))
		{
			oil_market += 2;
			oil_supply -= 2;
		}
		else
		{
			oil_market += oil_supply;
			oil_supply = 0;
		}

		if (checkSupply("garbage", 2))
		{
			garbage_market += 2;
			garbage_supply -= 2;
		}
		else
		{
			garbage_market += garbage_supply;
			garbage_supply = 0;
		}
		if (checkSupply("uranium", 1))
		{
			uranium_market += 1;
			uranium_supply -= 1;
		}
		else
		{
			uranium_market += uranium_supply;
			uranium_supply = 0;
		}

	}
	else if (step == 3)
	{

		if (checkSupply("coal", 3))
		{
			coal_market += 3;
			coal_supply -= 3;
		}
		else
		{
			coal_market += coal_supply;
			coal_supply = 0;
		}

		if (checkSupply("oil", 4))
		{
			oil_market += 4;
			oil_supply -= 4;
		}
		else
		{
			oil_market += oil_supply;
			oil_supply = 0;
		}

		if (checkSupply("garbage", 3))
		{
			garbage_market += 3;
			garbage_supply -= 3;
		}
		else
		{
			garbage_market += garbage_supply;
			garbage_supply = 0;
		}
		if (checkSupply("uranium", 1))
		{
			uranium_market += 1;
			uranium_supply -= 1;
		}
		else
		{
			uranium_market += uranium_supply;
			uranium_supply = 0;
		}
	}
	else
	{
		cout << "Invalid step." << endl;
	}

	//updating the state of supplies to make sure we are working with the right numbers
	//updateSupply();
}

int Market::getPrice(string type)
{
	//NOT SURE THIS IS THE BEST WAY TO IMPLEMENT
	if (type == "coal") {

		if (coal_market <= 3) coal_price = 8;
		else if (coal_market>3 && coal_market <= 6)coal_price = 7;
		else if (coal_market>6 && coal_market <= 9)coal_price = 6;
		else if (coal_market>9 && coal_market <= 12)coal_price = 5;
		else if (coal_market>12 && coal_market <= 15)coal_price = 4;
		else if (coal_market>15 && coal_market <= 18)coal_price = 3;
		else if (coal_market>18 && coal_market <= 21)coal_price = 2;
		else if (coal_market>21 && coal_market <= 24)coal_price = 1;
		return coal_price;
	}
	else if (type == "oil")
	{
		if (oil_market <= 3) oil_price = 8;
		else if (oil_market>3 && oil_market <= 6)oil_price = 7;
		else if (oil_market>6 && oil_market <= 9)coal_price = 6;
		else if (oil_market>9 && oil_market <= 12)oil_price = 5;
		else if (oil_market>12 && oil_market <= 15)oil_price = 4;
		else if (oil_market>15 && oil_market <= 18)oil_price = 3;
		else if (oil_market>18 && oil_market <= 21)oil_price = 2;
		else if (oil_market>21 && oil_market <= 24)oil_price = 1;
		return oil_price;
	}

	else if (type == "garbage")
	{
		if (garbage_market <= 3) garbage_price = 8;
		else if (garbage_market>3 && garbage_market <= 6)garbage_price = 7;
		else if (garbage_market>6 && garbage_market <= 9)garbage_price = 6;
		else if (garbage_market>9 && garbage_market <= 12)garbage_price = 5;
		else if (garbage_market>12 && garbage_market <= 15)garbage_price = 4;
		else if (garbage_market>15 && garbage_market <= 18)garbage_price = 3;
		else if (garbage_market>18 && garbage_market <= 21)garbage_price = 2;
		else if (garbage_market>21 && garbage_market <= 24)garbage_price = 1;

		return garbage_price;
	}
	else if (type == "uranium")
	{
		if (uranium_market == 1) uranium_price = 16;
		else if (uranium_market == 2) uranium_price = 14;
		else if (uranium_market == 3) uranium_price = 12;
		else if (uranium_market == 4) uranium_price = 10;
		else if (uranium_market == 5) uranium_price = 8;
		else if (uranium_market == 6) uranium_price = 7;
		else if (uranium_market == 7) uranium_price = 6;
		else if (uranium_market == 8) uranium_price = 5;
		else if (uranium_market == 9) uranium_price = 4;
		else if (uranium_market == 10) uranium_price = 3;
		else if (uranium_market == 11) uranium_price = 2;
		else if (uranium_market == 12) uranium_price = 1;
		return uranium_price;
	}


	return 0;
}


bool Market::checkSupply(string type, int number)
{
	//updateSupply();
	if (type == "coal")
	{
		return number <= coal_supply ? true : false;
	}
	else if (type == "oil")
	{
		return number <= oil_supply ? true : false;
	}

	else if (type == "garbage")
	{
		return number <= garbage_supply ? true : false;
	}
	else if (type == "uranium")
	{
		return number <= uranium_supply ? true : false;
	}

	return 0;
}


void Market::rtPurchase(string type, int number)
{

	if (type == "coal")
	{
		if (checkMarket("coal", number))
		{
			coal_market -= number;
		}
		else
		{
			cout << "Not enough coal in the market." << endl;
		}
	}
	else if (type == "oil")
	{
		if (checkMarket("oil", number))
		{
			oil_market -= number;
		}
		else
		{
			cout << "Not enough oil in the market." << endl;
		}
	}

	else if (type == "garbage")
	{
		if (checkMarket("garbage", number))
		{
			garbage_market -= number;
		}
		else
		{
			cout << "Not enough garbage in the market." << endl;
		}
	}
	else if (type == "uranium")
	{
		if (checkMarket("uranium", number))
		{
			uranium_market -= number;
		}
		else
		{
			cout << "Not enough uranium in the market." << endl;
		}
	}
	else
	{
		cout << "Invalid type." << endl;

	}

	//updating the state of supplies to make sure we are working with the right numbers
	//updateSupply();
}

bool Market::checkMarket(string type, int number)
{
	//updateSupply();
	if (type == "coal")
	{
		return number <= coal_market ? true : false;
	}
	else if (type == "oil")
	{
		return number <= oil_market ? true : false;
	}

	else if (type == "garbage")
	{
		return number <= garbage_market ? true : false;
	}
	else if (type == "uranium")
	{
		return number <= uranium_market ? true : false;
	}

	return 0;
}

void Market::toString()
{
	//updateSupply();

	cout << "RESOURCE TOKEN INFORMATION" << endl;
	cout << "================" << endl;
	cout << "================" << endl;
	cout << "TOTAL OF TOKENS --- " << endl;
	cout << "Coal: " << TOTAL_COAL << endl;
	cout << "Oil: " << TOTAL_OIL << endl;
	cout << "Garbage: " << TOTAL_GARBAGE << endl;
	cout << "Urianium: " << TOTAL_URANIUM << endl;


	cout << "================" << endl;

	cout << "Market ---  " << endl;
	cout << "Coal: " << coal_market << endl;
	cout << "Oil: " << oil_market << endl;
	cout << "Garbage: " << garbage_market << endl;
	cout << "Urianium: " << uranium_market << endl;

	cout << "================" << endl;

	cout << "SUPPLY ---  " << endl;
	cout << "Coal: " << coal_supply << endl;
	cout << "Oil: " << oil_supply << endl;
	cout << "Garbage: " << garbage_supply << endl;
	cout << "Urianium: " << uranium_supply << endl;
}