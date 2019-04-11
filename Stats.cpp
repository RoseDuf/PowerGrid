#include "Stats.h"



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
	//info about game
	//graph bars
	//writes to file
	cout << "IN UPDATE ---------------------------------------------------" << endl;
}
