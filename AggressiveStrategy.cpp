#include "AggressiveStrategy.hpp"

AggressiveStrategy::AggressiveStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

int AggressiveStrategy::getBidAmount(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket(); Maybe in main function?

    if( highestBidSoFar >= 3 && highestBidSoFar < PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex).getCardNumber() ) {
        // throw some exception // TODO
    }
    
    std::vector<PowerPlant> presentPowerPlantMarket = PowerPlant::peekPresentPowerPlantMarket();
    
    if( biddedPowerPlantIndex < presentPowerPlantMarket.size()-1 ) { // if the bidded index is NOT the largest in present power plant market
        
        for(int i = biddedPowerPlantIndex; i < presentPowerPlantMarket.size()-1; i++) { // presentPowerPlantMarket is sorted in ascending order
                
            if( presentPowerPlantMarket.at(i+1).getCardNumber() <= player->getTotalWallet()) {
                return -1;
            }
            else {
                
                if( player->getTotalWallet() >= highestBidSoFar+1 ) {
                    return highestBidSoFar+1;
                }
            }
        }
    }
    else { // if the bidded index IS the largest in present power plant market
        if( player->getTotalWallet() >= highestBidSoFar+1 ) {
            return highestBidSoFar+1;
        }
        else {
            return -1;
        }
    }
}
