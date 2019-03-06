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

    //GETS pointer to array of strings of ressource token TYPES NEEDED
	string getTypeRessourceTokenNeeded1();
    string getTypeRessourceTokenNeeded2();
    
    //SETS the ressource token TYPES NEEDED
	void setTypeRessourceTokenNeeded1(string _typeRessourceTokenNeeded1);
    
    //SETS the ressource token TYPES NEEDED
    void setTypeRessourceTokenNeeded2(string _typeRessourceTokenNeeded2);


    //GETS pointer to array to see how many of each ressource token is currently STOCKED on power plant card
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
   // string typeRessourceTokenNeeded[2];
    //int ressourceTokenStocked[2];
	int numRessourcesTokensNeeded;

	int numCitiesPowered;
};

