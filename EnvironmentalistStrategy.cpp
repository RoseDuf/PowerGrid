#include "EnvironmentalistStrategy.hpp"
#include "PowerPlant.hpp"

EnvironmentalistStrategy::EnvironmentalistStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

int Strategy::getBidAmount(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket();
    
    int amountToBid = 0;
    
    if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).isGreen() && player->getTotalWallet() >= highestBidSoFar+1 ) {
        amountToBid = highestBidSoFar + 1;
    }
    
    return amountToBid;
}
