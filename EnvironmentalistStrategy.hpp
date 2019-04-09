
#ifndef ENVIRONMENTALISTSTRATEGY_HPP_
#define ENVIRONMENTALISTSTRATEGY_HPP_

#include "Strategy.hpp"

class EnvironmentalistStrategy : public Strategy {
    public:
        EnvironmentalistStrategy(AIStrategyData backgroundInformation);
        virtual int getBidAmount(Player* player, int biddedPowerPlantIndex, int highestBigSoFar); // amounts less than 3 means the AI is passing on the bid / not bidding
};

#endif
