#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

BiddingDetails PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, Elektro highestBidSoFar) {
    return executePowerPlantBiddingStrategy(player, biddedPowerPlantIndex, highestBidSoFar.getTotalBalance());
}

BiddingDetails PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    return strategy->getBiddingDetails(player, biddedPowerPlantIndex, highestBidSoFar);
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
