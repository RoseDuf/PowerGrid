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
    //
    //constructor takes 2 possibles ressource tokens needed, if only is one needed, fill the second attribute with : ""
	//PowerPlant(int _cardNumber, int _numOfCitiesPowered, int numRessourcesTokensNeeded, string _ressourceTokenNeeded1, string _ressourceTokenNeeded2);
    PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed);
	~PowerPlant();

	int getCardNumber();
	void setCardNumber(int _cardNumber);

	int getCitiesPowered();
	void setCitiesPowered(int _number);
    
    void stockRT(string type, int num);
    int getRTStocked(string type, int num);
    int getRTNeeded(string type, int num);
    void powerCity(string type);
    bool checkIfNeeded(string type);
    bool checkSpace(string type, int num);
    bool checkIfEnoughStock(string type);

/*
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
*/
	 virtual void toString() override;

private:
    
    //bool twoTypes = false;
    
	int cardNumber;
    /*
    ResourceToken r1 = ResourceToken(0, "");
    ResourceToken r2 = ResourceToken(0, "");
	int numRessourcesTokensNeeded;
*/
	int numCitiesPowered;
    
    int oil_needed =0;
    int coal_needed = 0;
    int garbage_needed = 0;
    int uranium_needed = 0;
    
    int oil_stocked=0;
    int coal_stocked=0;
    int garbage_stocked=0;
    int uranium_stocked=0;
    bool green = false;
};

#endif
