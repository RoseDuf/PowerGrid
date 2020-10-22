//(Deniz)

#ifndef POWERGRIDAI_HPP_
#define POWERGRIDAI_HPP_

#include "Strategy.hpp"

class PowerGridAI {
    private:
        Strategy* strategy;
    
    public:
        PowerGridAI(Strategy* strategy);
        BiddingDetails executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, Elektro highestBidSoFar);
        BiddingDetails executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, int highestBidSoFar);
        ResourcePurchaseChoice executeResourceBuyingStrategy(const Player* player);
        std::string executeRegionChoosingStrategy(std::vector<std::string> alreadyChosenRegions);
        std::vector<City> executeCityBuildingStrategy(const Player* player, int gameStep);

        void changeStrategy(Strategy* strategy);
        ~PowerGridAI();
};

#endif
