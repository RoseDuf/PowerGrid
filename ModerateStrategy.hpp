
#ifndef MODERATESTRATEGY_HPP_
#define MODERATESTRATEGY_HPP_

#include "Strategy.hpp"

class ModerateStrategy : public Strategy {
    public:
        ModerateStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar); // amounts less than 3 means the AI is passing on the bid / not bidding
};

#endif
