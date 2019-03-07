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

    
    r1.setIdentifier(_typeRessourceTokenNeeded1);
    r2.setIdentifier(_typeRessourceTokenNeeded2);
    
    r1.setNumber(0);
    r2.setNumber(0);
    
    identifier = "Power Plant " + to_string(_cardNumber);
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
string PowerPlant::getTypeRessourceTokenNeeded1()
{
	return r1.getIndentifier();
}
//GETS array of strings of ressource token TYPES NEEDED
string PowerPlant::getTypeRessourceTokenNeeded2()
{
    return r2.getIndentifier();
}

//SETS the ressource token TYPES NEEDED
void PowerPlant::setTypeRessourceTokenNeeded1(string _typeRessourceTokenNeeded1)
{
    r1.setIdentifier(_typeRessourceTokenNeeded1);
   
}

//SETS the ressource token TYPES NEEDED
void PowerPlant::setTypeRessourceTokenNeeded2(string _typeRessourceTokenNeeded2)
{
      r2.setIdentifier(_typeRessourceTokenNeeded2);
}



int PowerPlant::getRessourceTokenStocked1()
{
   
	return r1.getNumber();
}


int PowerPlant::getRessourceTokenStocked2()
{
    
    return r2.getNumber();
}

//SETS the NUMBER of ressource token STOCKED in power plant card
void PowerPlant::setNumRessourceTokenStocked1(int _ressourceTokenStocked1)
{
    r1.setNumber(_ressourceTokenStocked1);
}

void PowerPlant::setNumRessourceTokenStocked2(int _ressourceTokenStocked2)
{
   r2.setNumber(_ressourceTokenStocked2);
}


void PowerPlant::toString()
{
    
    //if green power plant
    if (r1.getIndentifier()=="") {
    cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
        << "Ressource needed : " <<  "GREEN" << "\n" <<
        "Number of tokens needed : " << "NONE" << endl;
    }//if this power plant card only needs one type of ressource token
    else if(r2.getIndentifier()=="")
    {
    
	cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
		<< "Ressource needed : " <<  r1.getIndentifier() << "\n" <<
		"Number of tokens needed : " << numRessourcesTokensNeeded << "\n" << "In stock : " << r1.getIndentifier() << "(" << r1.getNumber() << ")" << endl;
    }
    
    //if this power plant card  needs one type of ressource token or another
    else
    {
        cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
        << "Ressources needed : " <<  r1.getIndentifier() << " or " << r2.getIndentifier() << "\n" <<
        "Number of tokens needed : " << numRessourcesTokensNeeded << "\n" << "In stock : " << r1.getIndentifier() << "(" << r1.getNumber() << ")" << " " << r2.getIndentifier() << "(" << r2.getNumber() << ")" <<  endl;
    }
}
