//(Rose)

#pragma once
#include "Observer.h"
#include "Game.hpp"

#include <fstream>
#include <iostream>
class Stats : public Observer
{
public:
	Stats();
	Stats(Game* game);
	~Stats();

	void Update();
	void Update2() {}
	void display();
	void display2() {}
private:
	Game *_subject;
	ofstream gameStats;
};

