//(Elsa or Isabelle)

#pragma once
#include "GameCard.h"
class SummaryCard :
	public GameCard
{
public:
	SummaryCard();
	~SummaryCard();

	virtual void toString() override;

private:

	void toStringSide1();
	void toStringSide2();

};

