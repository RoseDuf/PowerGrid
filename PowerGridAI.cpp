#include "PowerGridAI.hpp"

PowerGridAI::PowerGridAI(Strategy* strategy) : strategy(strategy) {}

void PowerGridAI::executePowerPlantBiddingStrategy() {
}

void PowerGridAI::executeResourceBuyingStrategy() {
}

void PowerGridAI::executeCityBuildingStrategy() {
}

PowerGridAI::~PowerGridAI() {
    delete strategy;
}
