#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

PowerPlant* PowerGridAI::executePowerPlantBiddingStrategy(Player* player) {
    return strategy->getBiddingChoice(player);
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
