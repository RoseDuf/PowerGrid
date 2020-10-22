//(Elsa or Isabelle)

#ifndef POWERPLANT_HPP_
#define POWERPLANT_HPP_

#include "GameCard.h"
#include <vector>
#include <map>
//#include "Market.hpp"

class PowerPlant :
	public GameCard
{
public:
	PowerPlant();

	PowerPlant(int _cardNumber, int _numOfCitiesPowered, int _coal_needed, int _oil_needed, int _garbage_needed, int _uranium_needed);
	virtual ~PowerPlant();

	int getCardNumber();
	void setCardNumber(int _cardNumber);

	int getCitiesPowered();
	void setCitiesPowered(int _number);

	//stocks a resource onto the power plant card
	void stockRT(std::string type, int num);

	//gets the number of a resource type stocked on power plant card
	int getRTStocked(std::string type);

	//gets the number of a resource type needed
	int getRTNeeded(std::string type);

    bool checkRT(std::string type, int num);    
    
	//consumes the required amount of a certain type of resource to power the city
	void powerCity(std::string type);

	//check if this type of resource is needed
	bool checkIfNeeded(std::string type);

	//cehck if there is space to stock more tokens
	bool checkSpace(std::string type, int num);

	//check if enough tokens are stocked to power the city
	bool checkIfEnoughStock(std::string type);
    bool isGreen();
	virtual void toString() override;

	int get_numCitiesPowered_ACTIVE();
    
    static void addToPowerPlantMarket(PowerPlant* powerPlantToAdd); // adds power plant card in the correct location
    static PowerPlant peekIthPowerPlantInMarket(int i); // looks at, but doesn't modify anything
    static PowerPlant peekIthPowerPlantInPresentMarket(int i); // looks at, but doesn't modify anything
    static PowerPlant peekIthPowerPlantInFutureMarket(int i); // looks at, but doesn't modify anything
    static std::vector<PowerPlant> peekPresentPowerPlantMarket();
    static std::vector<PowerPlant> peekFuturePowerPlantMarket();
    static void removeFromPowerPlantMarket(PowerPlant* powerPlantToRemove);
    static int getPowerPlantMarketSize();
    static bool isPowerPlantMarketEmpty();
    static void initializePowerPlantMarket();
    
private:
    static bool powerPlantInitialized;
    static std::map<int, PowerPlant*> powerPlantMarket; // is sorted in ascending order of power plant card numbers
	int numCitiesPowered_ACTIVE = 0;
	int cardNumber;
	int numCitiesPowered;

	int oil_needed = 0;
	int coal_needed = 0;
	int garbage_needed = 0;
	int uranium_needed = 0;

	int oil_stocked = 0;
	int coal_stocked = 0;
	int garbage_stocked = 0;
	int uranium_stocked = 0;
	bool green = false;
};

#endif
