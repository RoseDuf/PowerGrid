#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

BiddingDetails PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, Elektro highestBidSoFar) {
    return executePowerPlantBiddingStrategy(player, biddedPowerPlantIndex, highestBidSoFar.getTotalBalance());
}

BiddingDetails PowerGridAI::executePowerPlantBiddingStrategy(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    return strategy->getBiddingDetails(player, biddedPowerPlantIndex, highestBidSoFar);
}

ResourcePurchaseChoice PowerGridAI::executeResourceBuyingStrategy(const Player* player) {
    return strategy->getResourcePurchaseChoice(player);
}

std::vector<City> PowerGridAI::executeCityBuildingStrategy(const Player* player, int gameStep) {
    return strategy->getCityBuildingChoice(player, gameStep);
}

std::string PowerGridAI::executeRegionChoosingStrategy(std::vector<std::string> alreadyChosenRegions) {
    return strategy->chooseOneRegion(alreadyChosenRegions);
}

PowerGridAI::~PowerGridAI() {
    delete strategy;
}
