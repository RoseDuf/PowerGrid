#pragma once
class Observer
{
public:
	
	~Observer();
	virtual void Update() = 0;
	virtual void Update2() = 0;

protected:
	Observer();
};

