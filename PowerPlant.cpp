#include "PowerPlant.h"

PowerPlant::PowerPlant()
{
}

PowerPlant::PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed)
{
    cardNumber = _cardNumber;
    numCitiesPowered = _numOfCitiesPowered;
    coal_needed =
    
    coal_needed = _coal_needed;
    oil_needed = _oil_needed;
    garbage_needed = _garbage_needed;
    uranium_needed = _uranium_needed;
    
    if(coal_needed==0 && oil_needed==0 && garbage_needed==0 && uranium_needed==0) green = true;
    
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

bool PowerPlant::checkIfNeeded(string type)
{
    bool temp = true;
    if(type=="coal")
    {
        if(coal_needed==0) temp =false;
    }
    else if(type=="oil")
    {
        if(oil_needed==0) temp = false;
    }
    
    else if(type=="garbage")
    {
       if(garbage_needed==0) temp=false;
    }
    else if(type=="uranium")
    {
        if(uranium_needed==0) temp=false;
    }
    
    if(temp==false)cout << "This power plant can't be powered with this resource." << endl;
    return temp;
}

bool PowerPlant::checkSpace(string type, int num)
{
    bool temp = true;
    int needed = 0;
    if(type=="coal")
    {
        if(num>coal_needed*2)
        {
            needed = coal_needed*2;
            temp = false;
        }
    }
    else if(type=="oil")
    {
        if(num>oil_needed*2)
        {
            needed = oil_needed*2;
            temp = false;
        }
    }
    
    else if(type=="garbage")
    {
        if(num>garbage_needed*2)
        {
            needed = garbage_needed*2;
            temp = false;
        }
    }
    else if(type=="uranium")
    {
        if(num>uranium_needed*2)
        {
            needed = uranium_needed*2;
            temp = false;
        }
    }
    
    if(temp==false)cout << "Can't store as many tokens. Can store max: " << needed*2 << endl;
    return temp;
}

bool PowerPlant::checkIfEnoughStock(string type)
{
    bool temp = true;
    int needed = 0;
    if(type=="coal")
    {
        if(coal_stocked < coal_needed)
        {
            temp = false;
            needed = coal_needed - coal_stocked;
        }
   
    }
    else if(type=="oil")
    {
        if(oil_stocked < oil_needed)
        {
            temp = false;
            needed = oil_needed - oil_stocked;
        }
    }
    
    else if(type=="garbage")
    {
        if(garbage_stocked < garbage_needed)
        {
            temp = false;
            needed = garbage_stocked - garbage_stocked;
        }
    }
    else if(type=="uranium")
    {
        if(uranium_stocked < uranium_needed)
        {
            temp = false;
            needed = uranium_needed - uranium_stocked;
        }
    }
    
    if(temp==false)cout << "This power plant doesn't have enough resources to be powered. Still needs: " << needed << " tokens." << endl;
    return temp;
}

void PowerPlant::stockRT(string type, int num)
{
    if(type=="coal")
    {
        if(checkIfNeeded("coal") && checkSpace("coal", num)){
                coal_stocked+=num;
        }
    }
    else if(type=="oil")
    {
        if(checkIfNeeded("oil") && checkSpace("oil", num)){
            oil_stocked+=num;
        }
    }
    
    else if(type=="garbage")
    {
        if(checkIfNeeded("garbage") && checkSpace("garbage", num)){
            garbage_stocked+=num;
        }
    }
    else if(type=="uranium")
    {
        if(checkIfNeeded("uranium") && checkSpace("uranium", num)){
            uranium_stocked+=num;
        }
    }
    

}
int PowerPlant::getRTStocked(string type, int num)
{
    if(type=="coal")
    {
        return coal_stocked;
    }
    else if(type=="oil")
    {
        return oil_stocked;
    }
    
    else if(type=="garbage")
    {
        return garbage_stocked;
    }
    else if(type=="uranium")
    {
        return uranium_stocked;
    }
    return 0;
}

int PowerPlant::getRTNeeded(string type, int num)
{
    if(type=="coal")
    {
        return coal_needed;
    }
    else if(type=="oil")
    {
        return oil_needed;
    }
    
    else if(type=="garbage")
    {
        return garbage_needed;
    }
    else if(type=="uranium")
    {
        return uranium_needed;
    }
    return 0;
}

void PowerPlant::powerCity(string type)
{

    if(type=="coal")
    {
       if(checkIfNeeded("coal") && checkIfEnoughStock("coal"))
       {
          coal_stocked-=coal_needed;
       }
    }
    else if(type=="oil")
    {
        if(checkIfNeeded("oil") && checkIfEnoughStock("oil"))
        {
            oil_stocked-=oil_needed;
        }
    }
    
    else if(type=="garbage")
    {
        if(checkIfNeeded("garbage") && checkIfEnoughStock("garbage"))
        {
            garbage_stocked-=garbage_needed;
        }
    }
    else if(type=="uranium")
    {
        if(checkIfNeeded("uranium") && checkIfEnoughStock("uranium"))
        {
            uranium_stocked-=uranium_needed;
        }
    }
}


void PowerPlant::toString()
{
    if(green)
    {
        cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
        << "This is a GREEN power plant." << "\n" <<
        "Number of tokens needed : " << "NONE" << endl;
    
    }
    else
    {
    
        cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
        << "Ressource needed : " <<  endl;
        cout << "Coal: " << coal_needed << endl;
         cout << "Oil: " << oil_needed << endl;
         cout << "Garbage: " << garbage_needed << endl;
         cout << "Uranium: " << uranium_needed << endl;
        
        cout << "-------------------" << endl;
        
        cout << "Number of tokens stocked : " << endl;
        cout << "Coal: " << coal_stocked << endl;
        cout << "Oil: " << oil_stocked << endl;
        cout << "Garbage: " << garbage_stocked << endl;
        cout << "Uranium: " << uranium_stocked << endl;
    }

}
