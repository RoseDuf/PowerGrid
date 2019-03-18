#include "ResourceToken.hpp"

ResourceToken::ResourceToken()
{
}

/*
 
 tokens =  {{"coal",0},
            {"garbage",0},
            {"uranium",0},
            {"oil",0}};
 */
ResourceToken::ResourceToken(int _numCoal, int _numGarbage, int _numUranium, int _numOil)
{
	
    tokens[0].second = _numCoal;
    tokens[1].second = _numGarbage;
    tokens[2].second = _numUranium;
    tokens[3].second = _numOil;
    
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


