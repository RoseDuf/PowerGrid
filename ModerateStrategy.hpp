
#ifndef MODERATESTRATEGY_HPP_
#define MODERATESTRATEGY_HPP_

#include "Strategy.hpp"

class ModerateStrategy : public Strategy {
    public:
        ModerateStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<int> getCityBuildingChoice(int gameStep) = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
};

#endif
