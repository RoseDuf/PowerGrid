
#ifndef ENVIRONMENTALISTSTRATEGY_HPP_
#define ENVIRONMENTALISTSTRATEGY_HPP_

#include "Strategy.hpp"

class EnvironmentalistStrategy : public Strategy {
    public:
        EnvironmentalistStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<City> getCityBuildingChoice() = 0;
};

#endif
