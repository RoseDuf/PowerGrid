#pragma once
#include "Observer.h"
#include "Game.h"
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
};

