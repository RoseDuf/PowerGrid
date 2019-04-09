#ifndef POWERGRIDAI_HPP_
#define POWERGRIDAI_HPP_

#include "Strategy.hpp"

class PowerGridAI {
    private:
        Strategy* strategy;
    
    public:
        PowerGridAI(Strategy* strategy);
        int executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, Elektro highestBidSoFar);
        int executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, int highestBidSoFar);
        ResourcePurchaseChoice executeResourceBuyingStrategy();
        std::vector<int> executeCityBuildingStrategy();
        void changeStrategy(Strategy* strategy);
        ~PowerGridAI();
};

#endif
