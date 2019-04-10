#include "AggressiveStrategy.hpp"

AggressiveStrategy::AggressiveStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

int AggressiveStrategy::getBidAmount(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket(); Maybe in main function?

    if( highestBidSoFar >= 3 && highestBidSoFar < PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex).getCardNumber() ) {
        // throw some exception // TODO
    }
    
    if( biddedPowerPlantIndex < 0) { // if no power plant was chosen to be bid on
        std::vector<PowerPlant> presentPowerPlantMarket = PowerPlant::peekPresentPowerPlantMarket();
        
        for(int i = presentPowerPlantMarket.size()-1; i >= 0; i--) {
            if( player->getTotalWallet() >= presentPowerPlantMarket.at(i).getCardNumber() ) {
                return presentPowerPlantMarket.at(i).getCardNumber();
            }
        }
    }
    else { // if a power plant WAS chosen to be bid on
        return highestBidSoFar+1;
    }
        
    return -1; // if nothing else was returned, return -1, which means that no bid was made
}
