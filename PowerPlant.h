#ifndef POWERPLANT_H_
#define POWERPLANT_H_

#include "GameCard.h"
#include <vector>
#include "ResourceToken.hpp"

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
	string getTypeResourceTokenNeeded1();
    string getTypeResourceTokenNeeded2();
    
    //SETS the ressource token TYPES NEEDED
	void setTypeResourceTokenNeeded1(string _typeRessourceTokenNeeded1);
    void setTypeResourceTokenNeeded2(string _typeRessourceTokenNeeded2);


    //GETS ressource token currently STOCKED on power plan card
	int getResourceTokenStocked1();
    int getResourceTokenStocked2();
    
    //SETS the NUMBER of ressource token STOCKED in power plant card
	void setNumResourceTokenStocked1(int _numRessourceTokenStocked1);
    void setNumResourceTokenStocked2(int _numRessourceTokenStocked2);

	 virtual void toString() override;

private:
    
    bool twoTypes = false;
    
	int cardNumber;
    
    ResourceToken r1 = ResourceToken(0, "");
    ResourceToken r2 = ResourceToken(0, "");
	int numRessourcesTokensNeeded;

	int numCitiesPowered;
};

#endif
