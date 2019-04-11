
#ifndef AGGRESSIVESTRATEGY_HPP_
#define AGGRESSIVESTRATEGY_HPP_

#include "Strategy.hpp"

class AggressiveStrategy : public Strategy {
    public:
        AggressiveStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<int> getCityBuildingChoice() = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
};

#endif
