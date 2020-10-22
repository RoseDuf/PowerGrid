#pragma once
#include <iostream>
#include <fstream>
//(Elsa)

#include "Player.hpp"
#include "GraphBuilder.h"

/*BUILDER DESIGN PATTERN:

//We are using a GamePlayBuilder design pattern because we want to have a more
simple way of creating a complex object (Game), which is made up of many complex objects.
The objects that make up GamePlay themselves are dependent on each other.
The Builder design pattern creates an organized step-by-step way of creating the complex
GamePlay object.

Designed based off Builder template here:  https://github.com/7yadavrupesh/designpattern/blob/master/Builder%20Design%20Pattern/Builder%20Design%20Pattern%20In%20C%2B%2B.cpp

*/

using namespace std;

class Gameplay {


	//Game needs:::
	//PlayerBuilder
	//MapBuilder


private:
	string gameName;
	vector<Player*> players;	//players
	//GraphBuilder * graph;		//build map inside graphbuilder
	//string mapName;
	string phase;		//examples of phases are 'Buying Resources' 'Buying Cities' etc

public:
	Gameplay(string name): gameName{ name } {}

	//getters
	int getGameNum() {}
	vector<Player*> getPlayers(){return players; }
	//string getMap() { return graph->getMapName(); }	//maybe i need a graph too?
	string getPhase() { return phase; }



	//setters
	void setPlayers(const vector<Player*>& players) {}
	//void setMap() {}	//void setupmap() in Game.h
	void setPhase() {}

	/*void show() {
		cout << "Game name: " << gameName << endl
			<< "Name of Players : " << endl;
			for (int i = 0; i < players.size(); i++) {
				cout << players[i].getName();
			} 

			cout << endl;
	}*/


	//example of how we could save the game
	void printToFile() {
		ofstream myfile;
		myfile.open("tempGameSave.save");
		myfile << gameName << endl;
		myfile << "The players in this game are: " << endl;
		for (int i = 0; i < players.size(); i++) {
			myfile << "Name: " << players[i]->getName();
			myfile << "Color: " <<  players[i]->getColor();
			myfile << endl;
		}

		myfile << "The phase is " << phase;
		myfile.close();
	}



};
