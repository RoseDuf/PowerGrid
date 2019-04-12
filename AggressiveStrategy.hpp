
#ifndef AGGRESSIVESTRATEGY_HPP_
#define AGGRESSIVESTRATEGY_HPP_

#include "Strategy.hpp"

class AggressiveStrategy : public Strategy {
    public:
        AggressiveStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<City> getCityBuildingChoice(const Player* player, int gameStep); // aims to occupy one more city than power plants can power in the cheapest way possible
};

#endif
