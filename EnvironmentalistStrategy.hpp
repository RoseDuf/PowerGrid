
#ifndef ENVIRONMENTALISTSTRATEGY_HPP_
#define ENVIRONMENTALISTSTRATEGY_HPP_

#include "Strategy.hpp"

class EnvironmentalistStrategy : public Strategy {
    public:
        EnvironmentalistStrategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar);
        virtual std::vector<City> getCityBuildingChoice(const Player* player, int gameStep); // aims to occupy exactly the amount of cities that owned power plants can power in the cheapest way possible, except if there is a green power plant at index 3 of the present power plant market. If there is a green power plant at index 3 of the present power plant market, the AI player will aim to have one city less than the player with the least amount of cities to ensure that this AI player will bid last in next power plant bidding session (as desired in assignment 3's instructions) (by having the least amount of cities owned, but only by 1 city ideally)
        virtual ResourcePurchaseChoice getResourcePurchaseChoice(const Player* player);
};

#endif
