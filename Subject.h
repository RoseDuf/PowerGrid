#pragma once

#include "Observer.h"
#include <list>

using namespace std;
//avoiding circular dependency
class Observer;

class Subject
{
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();

private:
	list<Observer*> *_observers;
};

