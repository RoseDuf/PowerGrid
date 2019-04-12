#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <vector>
#include <tuple>
#include "Market.hpp"
#include "Player.hpp"
#include "Elektro.hpp"
#include "GraphBuilder.h"

// Typedef data received by Strategy
typedef std::tuple< Market,std::vector<Player*>, GraphBuilder* > AIStrategyData;

// Typedef data returned by Strategy
typedef std::tuple<int,PowerPlant,PowerPlant> BiddingDetails; // tuple<bidAmount, PowerPlant powerPlantBeingBiddedOn, PowerPlant powerPlantOfPassedPlayerBeingReplaced>
typedef std::tuple<int, int, int, int> ResourcePurchaseChoice; // resources in alphabetical order (coal, garbage, oil, uranium) // the ints correspond to the CHANGE from total

class Strategy {
    protected:
        AIStrategyData backgroundInformation;
    public:
        Strategy(AIStrategyData backgroundInformation);
        
        // biddedPowerPlantIndex < 0 && highestBidSoFar < 3 means no bid was yet made. BiddingDetails(int amountBidded (where values less than 3 mean no bid), PowerPlant bidded on, PowerPlant to replace) (if power plant that's bidded == power plant that's to replace, that means no power plant is being replaced)
        virtual BiddingDetails getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBigSoFar) = 0;
        
        virtual std::string chooseOneRegion(std::vector<std::string> alreadyChosenRegions);
        //LATER?:virtual std::string chooseRemainingRegions(std::vector<std::string> alreadyChosenRegions);
        virtual std::vector<City> getCityBuildingChoice(const Player* player, int gameStep) = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
        virtual ResourcePurchaseChoice getResourcePurchaseChoice(const Player* player) = 0;
        virtual ~Strategy();
};

#endif
