//(Rose)

#pragma once
#include "Observer.h"
#include "Game.hpp"
class Info : public Observer
{
public:
	Info();
	Info(Game* game);
	~Info();

	void Update();
	void Update2();
	void display();
	void display2();
private:
	Game * _subject;
	int phase = 0;
};

