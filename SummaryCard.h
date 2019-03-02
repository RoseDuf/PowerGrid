#pragma once
#include "GameCard.h"
class SummaryCard :
	public GameCard
{
public:
	SummaryCard();
	~SummaryCard();

	virtual void toString();

private:

	void toStringSide1();
	void toStringSide2();

};

