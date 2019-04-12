
#ifndef ENVIRONMENTALISTSTRATEGY_HPP_
#define ENVIRONMENTALISTSTRATEGY_HPP_

#include "Strategy.hpp"

class EnvironmentalistStrategy : public Strategy {
    public:
        EnvironmentalistStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<City> getCityBuildingChoice(const Player* player, int gameStep); // aims to occupy exactly the amount of cities that owned power plants can power in the cheapest way possible
};

#endif
