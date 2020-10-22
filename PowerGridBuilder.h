//(Elsa)

#pragma once

#include "GameplayBuilder.h"
#include "Player.hpp"

//GameplayBuilder concrete class: PowerGrid Builder
//Knows only how to build a PowerGrid game

class PowerGridBuilder : public GameplayBuilder {


	virtual void createGameplay(vector<Player*>& players, string phase) override { 
		
		g1 = new Gameplay("PowerGrid");}


	virtual void buildPlayers( vector<Player*>& players) override {
		g1->setPlayers(players);
	
	} //set actual players here
	//void buildMap(string file) override { g1->setMap(); } //set actual map here
	virtual void buildPhase(string phase) override { 
		
		g1->setPhase(); 
	}//set actual phase here



};
