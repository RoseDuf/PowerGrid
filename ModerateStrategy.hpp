
#ifndef MODERATESTRATEGY_HPP_
#define MODERATESTRATEGY_HPP_

#include "Strategy.hpp"

class ModerateStrategy : public Strategy {
    public:
        ModerateStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar); // If this player has enough resources to fully power pps and has less than avg player's elektros, then gets aggressive for buying best pp possible
        virtual std::vector<City> getCityBuildingChoice(const Player* player, int gameStep);
        virtual ResourcePurchaseChoice getResourcePurchaseChoice(const Player* player);
};

#endif
