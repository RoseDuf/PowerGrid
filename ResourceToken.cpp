#include "ResourceToken.hpp"

ResourceToken::ResourceToken()
{
}

ResourceToken::ResourceToken(int _number, string _identifier)
{
	number = _number;
	identifier = _identifier;
    
    tokenNames.push_back("coal");
    tokenNames.push_back("garbage");
    tokenNames.push_back("uranium");
    tokenNames.push_back("oil");
}

ResourceToken::~ResourceToken()
{
	// TO DO
}

void ResourceToken::toString() {
	cout << "Resource Token : " << this->number << " " << this->identifier << endl;
}


