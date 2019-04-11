
#ifndef ENVIRONMENTALISTSTRATEGY_HPP_
#define ENVIRONMENTALISTSTRATEGY_HPP_

#include "Strategy.hpp"

class EnvironmentalistStrategy : public Strategy {
    public:
        EnvironmentalistStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<int> getCityBuildingChoice() = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
};

#endif
