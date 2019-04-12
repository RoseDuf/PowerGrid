#pragma once
//code sourced from examples in lab classes
#include "Observer.h"
#include <list>
#include <iostream>

using namespace std;
//avoiding circular dependency
class Observer;

class Subject
{
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	virtual void Notify2();
	Subject();
	~Subject();

private:
	list<Observer*> *_observers;
};

