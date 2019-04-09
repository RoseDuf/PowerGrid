
#ifndef AGGRESSIVESTRATEGY_HPP_
#define AGGRESSIVESTRATEGY_HPP_

#include "Strategy.hpp"

class AggressiveStrategy : public Strategy {
    public:
        AggressiveStrategy(AIStrategyData backgroundInformation);
        virtual int getBidAmount(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar); // amounts less than 3 means the AI is passing on the bid / not bidding
};

#endif
