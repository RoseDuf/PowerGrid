#pragma once

#include "GameplayBuilder.h"

//GameplayBuilder concrete class: PowerGrid Builder
//Knows only how to build a PowerGrid game

class PowerGridBuilder : public GameplayBuilder {


	void createGameplay() { g1 = new Gameplay("PowerGrid");}
	virtual void buildPlayers() { g1->setPlayers(); } //set actual players here
	virtual void buildMap() { g1->setMap(); } //set actual map here
	virtual void buildPhase() { g1->setPhase(); }//set actual phase here



};