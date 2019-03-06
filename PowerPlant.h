#pragma once
#include "GameCard.h"
#include <vector>
#include "RessourceToken.h"

class PowerPlant :
	public GameCard
{
public:
	PowerPlant();
    
    //constructor takes 2 possibles ressource tokens needed, if only is one needed, fill the second attribute with : ""
	PowerPlant(int _cardNumber, int _numOfCitiesPowered, int numRessourcesTokensNeeded, string _ressourceTokenNeeded1, string _ressourceTokenNeeded2);
    
	~PowerPlant();

	int getCardNumber();
	void setCardNumber(int _cardNumber);

	int getCitiesPowered();
	void setCitiesPowered(int _number);

    //GETS ressource token string NEEDED
	string getTypeRessourceTokenNeeded1();
    string getTypeRessourceTokenNeeded2();
    
    //SETS the ressource token TYPES NEEDED
	void setTypeRessourceTokenNeeded1(string _typeRessourceTokenNeeded1);
    void setTypeRessourceTokenNeeded2(string _typeRessourceTokenNeeded2);


    //GETS ressource token currently STOCKED on power plan card
	int getRessourceTokenStocked1();
    int getRessourceTokenStocked2();
    
    //SETS the NUMBER of ressource token STOCKED in power plant card
	void setNumRessourceTokenStocked1(int _numRessourceTokenStocked1);
    void setNumRessourceTokenStocked2(int _numRessourceTokenStocked2);

	 virtual void toString() override;

private:
    
    bool twoTypes = false;
    
	int cardNumber;
    
    RessourceToken r1 = RessourceToken(0, "");
    RessourceToken r2 = RessourceToken(0, "");
	int numRessourcesTokensNeeded;

	int numCitiesPowered;
};

