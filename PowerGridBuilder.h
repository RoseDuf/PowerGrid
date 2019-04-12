#pragma once

#include "GameplayBuilder.h"
#include "player.hpp"

//GameplayBuilder concrete class: PowerGrid Builder
//Knows only how to build a PowerGrid game

class PowerGridBuilder : public GameplayBuilder {


	void createGameplay(vector<Player*>& players, string map, string phase) override { g1 = new Gameplay("PowerGrid");}
	void buildPlayers( vector<Player*>& players) override {g1->setPlayers(players); } //set actual players here
	void buildMap(string file) override { g1->setMap(); } //set actual map here
	void buildPhase(string phase) override { g1->setPhase(); }//set actual phase here



};