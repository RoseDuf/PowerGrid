#include "Stats.h"

#include <fstream>
#include <iostream>

Stats::Stats()
{
}

Stats::Stats(Game* game)
{
	_subject = game;
	_subject->Attach(this);
}
Stats::~Stats()
{
	_subject->Detach(this);
}

void Stats::Update()
{
	display();
}

void Stats::display()
{
	cout << "--------------------------------------------------------------------------DISPLAYING AFTER BEING NOTIFIED" << endl;
	ofstream gameStats;
	gameStats.open("STATS.txt");
	gameStats << "----------------------------------------" << endl;
	gameStats << "USEFUL STATS" << endl;
	gameStats << "----------------------------------------" << endl;

	gameStats << endl;
	gameStats << endl;


	vector<Player*>  temp = *_subject->getPlayers();

	gameStats << "-----------------" << endl;
	gameStats << "NUMBER OF PLAYERS" << endl;
	//number of players in the game
	gameStats << temp.size();

	gameStats << "-----------------" << endl;
	gameStats << "NUMBER OF CITIES" << endl;
	//Player number of cities

	for (int i = 0; i < temp.size() ; i++)
	{
		//gameStats << "Player " << (i + 1) << endl;
		gameStats << temp[i]->getName() << endl;
		
		for (int j = 0; j < temp[i]->getCitiesOwned().size(); j++)
		{
			gameStats << " * ";
		}

		gameStats << endl;
		

	}
	/*
	gameStats << "-----------------" << endl;
	gameStats << "NAME OF CITIES" << endl;
	//cities owned , by name
	for (int i = 0; i < temp.size(); i++)
	{
		//gameStats << "Player " << (i + 1) << endl;
		gameStats << temp[i]->getName() << endl;

		for (int j = 0; j < temp[i]->getCitiesOwned().size(); j++)
		{
			gameStats << temp[i]->getCitiesOwned()[i].getCityName();
		}

		gameStats << endl;


	}
	*/
	gameStats << "-----------------" << endl;
	gameStats << "NUMBER OF POWERPLANTS" << endl;
	//Players number of powerplants
	for (int i = 0; i < temp.size(); i++)
	{
		//gameStats << "Player " << (i + 1) << endl;
		gameStats << temp[i]->getName() << endl;

		for (int j = 0; j < temp[i]->getPowerPlant().size(); j++)
		{
			gameStats << " * ";
		}

		gameStats << endl;


	}

	gameStats << "-----------------" << endl;
	gameStats << "NUMBER OF RESOURCE TOKENS PER TYPE" << endl;
	//Player number of each token type
	for (int i = 0; i < temp.size(); i++)
	{
		//gameStats << "Player " << (i + 1) << endl;
		gameStats << temp[i]->getName() << endl;

		gameStats << "COAL: ";
		for (int j = 0; j < temp[i]->getTotalCoal(); j++)
		{
			gameStats << " * ";
		}
		gameStats << endl;

		gameStats << "OIL: ";
		for (int j = 0; j < temp[i]->getTotalOil(); j++)
		{
			gameStats << " * ";
		}
		gameStats << endl;

		gameStats << "GARBAGE: ";
		for (int j = 0; j < temp[i]->getTotalGarbage(); j++)
		{
			gameStats << " * ";
		}
		gameStats << endl;

		gameStats << "URANIUM: ";
		for (int j = 0; j < temp[i]->getTotalUranium(); j++)
		{
			gameStats << " * ";
		}


		gameStats << endl;
		gameStats << endl;

	}


	gameStats.close();

}
