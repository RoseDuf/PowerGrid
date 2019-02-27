#include "RessourceToken.h"

RessourceToken::RessourceToken()
{
}

RessourceToken::RessourceToken(int _number, string _identifier)
{
	number = _number;
	identifier = _identifier;
    
    tokenNames.push_back("coal");
    tokenNames.push_back("garbage");
    tokenNames.push_back("uranium");
    tokenNames.push_back("oil");
}

RessourceToken::~RessourceToken()
{
	// TO DO
}

void RessourceToken::toString() {
	cout << "Ressource Token : " << this->number << " " << this->identifier << endl;
}


