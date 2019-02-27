#pragma once
#include "GameCard.h"
#include <vector>

class PowerPlant :
	public GameCard
{
public:
	PowerPlant();
	PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _numTokensNeeded, vector<string> ressourceTokenNeeded);
	~PowerPlant();

	int getCardNumber();
	void setCardNumber(int _cardNumber);

	int getCitiesPowered();
	void setCitiesPowered(int _number);


	//still thinking of better way to packaged and access this***
	vector<string> getRessourceTokenNeeded();
	void setRessourceTokenNeeded(vector<string> _ressourcesNeeded);

	vector<string> getRessourceTokenStocked();
	void setRessourceTokenStocked(vector<string> _ressourcesStocked);

	 void toString();

private:
	int cardNumber;
	vector<string> ressourceTokenNeeded;
	vector<string> ressourceTokenStocked;
	int numRessourcesTokensNeeded;

	int numCitiesPowered;
};

