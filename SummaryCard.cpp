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
	cout << "\n" <<"\n" <<
    
        "0" << "\t" << "10" << "\t" << "7" << "\t" << "82" << "\t" << "14" << "\t" << "129" << "\n" <<
        "1" << "\t" << "22" << "\t" << "8" << "\t" << "80" << "\t" << "15" << "\t" << "134" << "\n" <<
        "2" << "\t" << "33" << "\t" << "9" << "\t" << "99" << "\t" << "16" << "\t" << "138" << "\n" <<
        "3" << "\t" << "44" << "\t" << "10" << "\t" << "105" << "\t" << "17" << "\t" << "142" << "\n" <<
        "4" << "\t" << "54" << "\t" << "11" << "\t" << "112" << "\t" << "18" << "\t" << "145" << "\n" <<
        "5" << "\t" << "64" << "\t" << "12" << "\t" << "118" << "\t" << "19" << "\t" << "148" << "\n" <<
        "6" << "\t" << "73" << "\t" << "13" << "\t" << "124" << "\t" << "20" << "\t" << "150"
    
    << endl;
}
