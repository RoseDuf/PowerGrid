#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

BiddingChoice PowerGridAI::executePowerPlantBiddingStrategy(Player* player, Elektro highestBidSoFar) {
    return strategy->getBiddingChoice(player, highestBidSoFar);
}

BiddingChoice PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int highestBidSoFar) {
    return strategy->getBiddingChoice(player, highestBidSoFar);
}

ResourcePurchaseChoice PowerGridAI::executeResourceBuyingStrategy() {
    return strategy->getResourcePurchaseChoice();
}

std::vector<int> PowerGridAI::executeCityBuildingStrategy() {
    return strategy->getCityBuildingChoice();
}

PowerGridAI::~PowerGridAI() {
    delete strategy;
}
