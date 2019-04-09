#include "ModerateStrategy.hpp"

ModerateStrategy::ModerateStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

int ModerateStrategy::getBidAmount(Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket(); Maybe in main function?
    
    int amountToBid = -1;
    
    srand(time(0));
    int zeroOrOne = rand() % 2;
    
    if( zeroOrOne == 0 ) { // ~50% chance
        amountToBid = highestBidSoFar + 1;
    }
    
    return amountToBid;
}
