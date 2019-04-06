#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <vector>
#include <tuple>
#include "Market.hpp"
#include "Player.hpp"


typedef std::tuple< Market*,std::vector<Player*> > AIStrategyData;

class Strategy {
    private:
        AIStrategyData backgroundInformation;
    public:
        Strategy(AIStrategyData backgroundInformation);
};

#endif
