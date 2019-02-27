#include "House.h"



House::House()
{
}

House::House(string _identifier)
{

    identifier = _identifier;
    tokenNames.push_back("pink");
    tokenNames.push_back("red");
    tokenNames.push_back("black");
    tokenNames.push_back("blue");
    tokenNames.push_back("green");


	
}

House::~House()
{
	// TO DO
}



void House::toString() {
    cout << "House Token : "  << this->identifier << endl;
}



