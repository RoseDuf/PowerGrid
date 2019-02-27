#include "SummaryCard.h"

SummaryCard::SummaryCard()
{
}


SummaryCard::~SummaryCard()
{
	// TO DO
}

void SummaryCard::toString() {
	toStringSide1();
	toStringSide2();
}

void SummaryCard::toStringSide1()
{
	cout << "SUMARRY CAR: TURN \n" << "=================== \n"
		<< "1.DETERMINE TURN ORDER \n"
		<< "2.BUY POWER PLANT \n" << "  The first player begins \n" << "  Per round, each may buy only one power plant. \n"
		<< "3.BUY RAW MATERIALS \n" << "  The last player beings.\n" << "  Maximum double input per power plant.\n"
		<< "4.BUILDING \n" << "  The last player begins.\n"
		<< "5.BUREAUCRACY \n" << "  -Get money.\n" << "  -In phase 1 and 2: Place highest power plant under de stack.\n" 
		<< "  -In phase 3: Remove the lower power plant from the game. \n"
		<< "  -Restock raw materials" << endl;

}

void SummaryCard::toStringSide2()
{
	// TO DO
}
