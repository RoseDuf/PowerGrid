#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

int PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, Elektro highestBidSoFar) {
    return executePowerPlantBiddingStrategy(player, biddedPowerPlantIndex, highestBidSoFar.getTotalBalance());
}

int PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    return strategy->getBidAmount(player, biddedPowerPlantIndex, highestBidSoFar);
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
