#include "PowerPlant.h"

PowerPlant::PowerPlant()
{
}

PowerPlant::PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _numRessourcesTokensNeeded, vector<string> _ressourceTokenNeeded)
{
	cardNumber = _cardNumber;
	numCitiesPowered = _numOfCitiesPowered;
	numRessourcesTokensNeeded = _numRessourcesTokensNeeded;
	ressourceTokenNeeded = _ressourceTokenNeeded;
}

PowerPlant::~PowerPlant()
{
	// TO DO
}

int PowerPlant::getCardNumber()
{
	return cardNumber;
}

void PowerPlant::setCardNumber(int _cardNumber)
{
	cardNumber = _cardNumber;
}

int PowerPlant::getCitiesPowered()
{
	return numCitiesPowered;
}

void PowerPlant::setCitiesPowered(int _citiesPowered)
{
	numCitiesPowered = _citiesPowered;
}

vector<string> PowerPlant::getRessourceTokenNeeded()
{
	return ressourceTokenNeeded;
}

void PowerPlant::setRessourceTokenNeeded(vector<string> _ressourceTokenNeeded)
{
	//to do 
}

vector<string> PowerPlant::getRessourceTokenStocked()
{
	return ressourceTokenStocked;
}

void PowerPlant::setRessourceTokenStocked(vector<string> _ressourcesStocked)
{
	//to do
}

void PowerPlant::toString()
{
	cout << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
		<< "Ressource needed : " << ressourceTokenNeeded.front() << "\n" <<
		"Number of tokens needed : " << numRessourcesTokensNeeded << "\n" << "In stock : " << endl;

		//to do : In stock
	 
}