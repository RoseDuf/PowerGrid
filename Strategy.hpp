#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <vector>
#include <tuple>
#include "Market.hpp"
#include "Player.hpp"
#include "Elektro.hpp"

// Typedef data received by Strategy
typedef std::tuple< Market*,std::vector<Player*> > AIStrategyData;

// Typedef data returned by Strategy
typedef std::tuple<Elektro, PowerPlant*> BiddingChoice;
typedef std::tuple<Market*, int, int, int, int> ResourcePurchaseChoice; // the ints correspond to the CHANGE from total (positive value means amount added to total, negative means amount taken away from total) in Market (0 means no change)

class Strategy {
    private:
        AIStrategyData backgroundInformation;
    public:
        Strategy(AIStrategyData backgroundInformation);
        virtual BiddingChoice getBiddingChoice(Player* player) = 0;
        virtual ResourcePurchaseChoice getResourcePurchaseChoice() = 0;
        virtual std::vector<int> getCityBuildingChoice() = 0; // returns a vector of city numbers (a.k.a. map vertice numbers)
        virtual ~Strategy();
};

#endif
