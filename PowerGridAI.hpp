#ifndef POWERGRIDAI_HPP_
#define POWERGRIDAI_HPP_

#include "Strategy.hpp"

class PowerGridAI {
    private:
        Strategy* strategy;
    
    public:
        PowerGridAI(Strategy* strategy);
        BiddingChoice executePowerPlantBiddingStrategy(Player* player, Elektro highestBidSoFar);
        BiddingChoice executePowerPlantBiddingStrategy(Player* player, int highestBidSoFar);
        ResourcePurchaseChoice executeResourceBuyingStrategy();
        std::vector<int> executeCityBuildingStrategy();
        void changeStrategy(Strategy* strategy);
        ~PowerGridAI();
};

#endif
