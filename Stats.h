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
	void Update2() {}
	void display();
	void display2() {}
private:
	Game *_subject;
};

