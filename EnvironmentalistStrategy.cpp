#include "EnvironmentalistStrategy.hpp"
#include "PowerPlant.hpp"

EnvironmentalistStrategy::EnvironmentalistStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

BiddingChoice Strategy::getBiddingChoice(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket();
    
    bool isBidding = false;
    
    int amountToBid = 0;
    
    if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).isGreen() && player->getTotalWallet() >= highestBidSoFar+1 ) {
        isBidding = true;
        amountToBid = highestBidSoFar + 1;
    }
    
    return BiddingChoice(isBidding, amountToBid);
}
