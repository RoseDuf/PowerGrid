#ifndef POWERGRIDAI_HPP_
#define POWERGRIDAI_HPP_

#include "Strategy.hpp"

class PowerGridAI {
    private:
        Strategy* strategy;
    
    public:
        PowerGridAI(Strategy* strategy);
        PowerPlant* executePowerPlantBiddingStrategy(Player* player);
        ResourcePurchaseChoice executeResourceBuyingStrategy();
        std::vector<int> executeCityBuildingStrategy();
        void changeStrategy(Strategy* strategy);
        ~PowerGridAI();
};

#endif
