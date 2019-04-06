#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

BiddingChoice PowerGridAI::executePowerPlantBiddingStrategy() {
    return strategy->getBiddingChoice();
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
