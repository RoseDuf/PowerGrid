#include "EnvironmentalistStrategy.hpp"
#include "PowerPlant.hpp"

EnvironmentalistStrategy::EnvironmentalistStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

int EnvironmentalistStrategy::getBidAmount(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket(); Maybe in main function?
    
    int amountToBid = 0;
    
    if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).isGreen() && player->getTotalWallet() >= highestBidSoFar+1 ) {
        amountToBid = highestBidSoFar + 1;
    }
    
    return amountToBid;
}
