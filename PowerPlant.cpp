#include "PowerPlant.hpp"

using namespace std;

std::map<int, PowerPlant*> PowerPlant::powerPlantMarket;

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

	if (coal_needed == 0 && oil_needed == 0 && garbage_needed == 0 && uranium_needed == 0) green = true;

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
	if (type == "coal")
	{
		if (coal_needed == 0) temp = false;
	}
	else if (type == "oil")
	{
		if (oil_needed == 0) temp = false;
	}

	else if (type == "garbage")
	{
		if (garbage_needed == 0) temp = false;
	}
	else if (type == "uranium")
	{
		if (uranium_needed == 0) temp = false;
	}

	if (temp == false)cout << "This power plant can't be powered with this resource." << endl;
	return temp;
}

bool PowerPlant::checkSpace(string type, int num)
{
	bool temp = true;
	int needed = 0;
	if (type == "coal")
	{
		if (num>coal_needed * 2)
		{
			needed = coal_needed * 2;
			temp = false;
		}
	}
	else if (type == "oil")
	{
		if (num>oil_needed * 2)
		{
			needed = oil_needed * 2;
			temp = false;
		}
	}

	else if (type == "garbage")
	{
		if (num>garbage_needed * 2)
		{
			needed = garbage_needed * 2;
			temp = false;
		}
	}
	else if (type == "uranium")
	{
		if (num>uranium_needed * 2)
		{
			needed = uranium_needed * 2;
			temp = false;
		}
	}

	if (temp == false)cout << "Can't store as many tokens. Can store max: " << needed * 2 << endl;
	return temp;
}

bool PowerPlant::checkIfEnoughStock(string type)
{
	bool temp = true;
	int needed = 0;
	if (type == "coal")
	{
		if (coal_stocked < coal_needed)
		{
			temp = false;
			needed = coal_needed - coal_stocked;
		}

	}
	else if (type == "oil")
	{
		if (oil_stocked < oil_needed)
		{
			temp = false;
			needed = oil_needed - oil_stocked;
		}
	}

	else if (type == "garbage")
	{
		if (garbage_stocked < garbage_needed)
		{
			temp = false;
			needed = garbage_stocked - garbage_stocked;
		}
	}
	else if (type == "uranium")
	{
		if (uranium_stocked < uranium_needed)
		{
			temp = false;
			needed = uranium_needed - uranium_stocked;
		}
	}

	if (temp == false)cout << "This power plant doesn't have enough resources to be powered. Still needs: " << needed << " tokens." << endl;
	return temp;
}

void PowerPlant::stockRT(string type, int num)
{
	if (type == "coal")
	{
		if (checkIfNeeded("coal") && checkSpace("coal", num)) {
			coal_stocked += num;
			//market->rtPurchase("coal", num);
		}
	}
	else if (type == "oil")
	{
		if (checkIfNeeded("oil") && checkSpace("oil", num)) {
			oil_stocked += num;
			//market->rtPurchase("oil", num);
		}
	}

	else if (type == "garbage")
	{
		if (checkIfNeeded("garbage") && checkSpace("garbage", num)) {
			garbage_stocked += num;
			// market->rtPurchase("garbage", num);
		}
	}
	else if (type == "uranium")
	{
		if (checkIfNeeded("uranium") && checkSpace("uranium", num)) {
			uranium_stocked += num;
			// market->rtPurchase("uranium", num);
		}
	}


}
int PowerPlant::getRTStocked(string type)
{
	if (type == "coal")
	{
		return coal_stocked;
	}
	else if (type == "oil")
	{
		return oil_stocked;
	}

	else if (type == "garbage")
	{
		return garbage_stocked;
	}
	else if (type == "uranium")
	{
		return uranium_stocked;
	}
	return 0;
}

int PowerPlant::getRTNeeded(string type)
{
	if (type == "coal")
	{
		return coal_needed;
	}
	else if (type == "oil")
	{
		return oil_needed;
	}

	else if (type == "garbage")
	{
		return garbage_needed;
	}
	else if (type == "uranium")
	{
		return uranium_needed;
	}
	return 0;
}
int PowerPlant::get_numCitiesPowered_ACTIVE()
{
	return numCitiesPowered_ACTIVE;
}
void PowerPlant::powerCity(string type)
{
	if (green)
	{
		cout << "Powered city with GREEN power plant." << endl;
	}
	else
	{
		if (type == "coal")
		{
			if (checkIfNeeded("coal") && checkIfEnoughStock("coal"))
			{
				coal_stocked -= coal_needed;
				numCitiesPowered_ACTIVE += numCitiesPowered;
				//market->addToSupply("coal", coal_needed);
			}
		}
		else if (type == "oil")
		{
			if (checkIfNeeded("oil") && checkIfEnoughStock("oil"))
			{
				oil_stocked -= oil_needed;
				numCitiesPowered_ACTIVE += numCitiesPowered;
				//market->addToSupply("oil", oil_needed);
			}
		}

		else if (type == "garbage")
		{
			if (checkIfNeeded("garbage") && checkIfEnoughStock("garbage"))
			{
				garbage_stocked -= garbage_needed;
				numCitiesPowered_ACTIVE += numCitiesPowered;
				//market->addToSupply("garbage", garbage_needed);
			}
		}
		else if (type == "uranium")
		{
			if (checkIfNeeded("uranium") && checkIfEnoughStock("uranium"))
			{
				uranium_stocked -= uranium_needed;
				numCitiesPowered_ACTIVE += numCitiesPowered;
				//market->addToSupply("uranium", uranium_needed);
			}
		}
	}
}

bool PowerPlant::isGreen() {
    return this->green;
}

void PowerPlant::toString()
{
	if (green)
	{
		cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
			<< "This is a GREEN power plant." << "\n" <<
			"Number of tokens needed : " << "NONE" << endl;

	}
	else
	{

		cout << "\n" << "\n" << "Power Plant Card Info: " << "\n" << "Card Number : " << cardNumber << "\n" << "Number of cities powered : " << numCitiesPowered << "\n"
			<< "Ressource needed : " << endl;
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

void PowerPlant::removeFromPowerPlantMarket(PowerPlant* powerPlantToRemove) {
    for(auto it = powerPlantMarket.begin(); it != powerPlantMarket.end(); it++) {
        if( it->first == powerPlantToRemove->getCardNumber() ) {
            
            powerPlantMarket.erase(it); // don't also delete it (as in the C++ delete keyword which frees memory) because the power plant card may still be needed in a context other than the power plant market
        }
    }
}

void PowerPlant::addToPowerPlantMarket(PowerPlant* powerPlantToAdd) {
    powerPlantMarket.insert( std::make_pair(powerPlantToAdd->getCardNumber(), powerPlantToAdd) );
}


PowerPlant PowerPlant::peekIthPowerPlantInMarket(int i) {
    if(i > 7) {
        // throw some exception // TODO
    }
    else {
        auto it = powerPlantMarket.begin();
        for(int a = 0; a < powerPlantMarket.size(); a++) {
            if(a == i) {
                return *(it->second);
            }
            it++;
        }
    }
    // throw some exception // TODO
}

PowerPlant PowerPlant::peekIthPowerPlantInPresentMarket(int i) {
    if(i > 3) {
        // throw some exception // TODO
    }
    else {
        auto it = powerPlantMarket.begin();
        for(int a = 0; a < powerPlantMarket.size(); a++) {
            if(a == i) {
                return *(it->second);
            }
            it++;
        }
    }
    // throw some exception // TODO
}

PowerPlant PowerPlant::peekIthPowerPlantInFutureMarket(int i) {
    if(i > 3) {
        // throw some exception // TODO
    }
    else {
        i = i + 4;
        auto it = powerPlantMarket.begin();
        for(int a = 4; a < powerPlantMarket.size(); a++) {
            if(a == i) {
                return *(it->second);
            }
            it++;
        }
    }
    // throw some exception // TODO
}
