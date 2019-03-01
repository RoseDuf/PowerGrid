#include "PowerPlant.h"

PowerPlant::PowerPlant()
{
}

 //constructor takes 2 possibles ressource tokens needed, if only is one needed, fill the second attribute with : ""
PowerPlant::PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _numRessourcesTokensNeeded, string _typeRessourceTokenNeeded1, string _typeRessourceTokenNeeded2)
{
	cardNumber = _cardNumber;
	numCitiesPowered = _numOfCitiesPowered;
	numRessourcesTokensNeeded = _numRessourcesTokensNeeded;

    //filling array with types of ressource tokens needed
    typeRessourceTokenNeeded[0] = _typeRessourceTokenNeeded1;
    typeRessourceTokenNeeded[1]= _typeRessourceTokenNeeded2;
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

//GETS array of strings of ressource token TYPES NEEDED
string* PowerPlant::getTypeRessourceTokenNeeded()
{
	return typeRessourceTokenNeeded;
}

//SETS the ressource token TYPES NEEDED
void PowerPlant::setTypeRessourceTokenNeeded(string _typeRessourceTokenNeeded1, string _typeRessourceTokenNeeded2)
{
    typeRessourceTokenNeeded[0] = _typeRessourceTokenNeeded1;
    typeRessourceTokenNeeded[1]= _typeRessourceTokenNeeded2;
}


//GETS array to see how many of each ressource token is currently STOCKED on power plant card
int* PowerPlant::getRessourceTokenStocked()
{
    /* How to access the elements in array:
     
     //source:https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
     
     PowerPlant p = PowerPlant(23, 2, 1, "coal", "garbage");
     cout << "Ressource tokens of p :" << endl;
     
     string* ptr;
     ptr = p.getTypeRessourceTokenNeeded();
     for(int i = 0; i< 2; i++)
     {
     cout << *(ptr + i) << endl;
     }
     
     */
	return ressourceTokenStocked;
}

//SETS the NUMBER of ressource token STOCKED in power plant card
void PowerPlant::setNumRessourceTokenStocked(int _ressourceTokenStocked1, int _ressourceTokenStocked2)
{
    ressourceTokenStocked[0] = _ressourceTokenStocked1;
    ressourceTokenStocked[1] = _ressourceTokenStocked2;
}

void PowerPlant::toString()
{
    
    //if this power plant card only needs one type of ressource token
    if(typeRessourceTokenNeeded[1]=="")
    {
    
	cout << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
		<< "Ressource needed : " <<  typeRessourceTokenNeeded[0] << "\n" <<
		"Number of tokens needed : " << numRessourcesTokensNeeded << "\n" << "In stock : " << endl;
    }
    
    //if this power plant card  needs one type of ressource token or another
    else
    {
        cout << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
        << "Ressources needed : " <<  typeRessourceTokenNeeded[0] << " or " << typeRessourceTokenNeeded[1] << "\n" <<
        "Number of tokens needed : " << numRessourcesTokensNeeded << "\n" << "In stock : " << endl;
    }
		//to do : In stock
    
    
	 
}