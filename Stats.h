#pragma once
#include "Observer.h"
#include "Game.h"

#include <fstream>
#include <iostream>
class Stats : public Observer
{
public:
	Stats();
	Stats(Game* game);
	~Stats();

	void Update();
	void display();
private:
	Game *_subject;
	ofstream gameStats;
};

