#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <vector>
#include <tuple>
#include "Market.hpp"
#include "Player.hpp"
#include "Elektro.hpp"
#include "GraphBuilder.h"

// Typedef data received by Strategy
typedef std::tuple< Market*,std::vector<Player*>, GraphBuilder* > AIStrategyData;

// Typedef data returned by Strategy
typedef std::tuple<int,PowerPlant,PowerPlant> BiddingDetails; // tuple<bidAmount, PowerPlant powerPlantBeingBiddedOn, PowerPlant powerPlantOfPassedPlayerBeingReplaced>
typedef std::tuple<Market*, int, int, int, int> ResourcePurchaseChoice; // the ints correspond to the CHANGE from total (positive value means amount added to total, negative means amount taken away from total) in Market (0 means no change)

class Strategy {
    protected:
        AIStrategyData backgroundInformation;
    public:
        Strategy(AIStrategyData backgroundInformation);
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar) = 0; // amounts less than 3 means the AI is passing on the bid / not bidding
        virtual std::string chooseOneRegion(std::vector<std::string> alreadyChosenRegions);
        //LATER?:virtual std::string chooseRemainingRegions(std::vector<std::string> alreadyChosenRegions);
        virtual ResourcePurchaseChoice getResourcePurchaseChoice() = 0;
        virtual std::vector<int> getCityBuildingChoice() = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
        virtual ~Strategy();
};

#endif
