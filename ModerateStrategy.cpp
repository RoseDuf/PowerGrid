#include "ModerateStrategy.hpp"

ModerateStrategy::ModerateStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

BiddingDetails ModerateStrategy::getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
    //This line should probably be elsewhere.: PowerPlant::initializePowerPlantMarket(); Maybe in main function?
    
    if( highestBidSoFar >= 3 && highestBidSoFar < PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex).getCardNumber() ) {
        // throw some exception // TODO
    }
    
    if( (biddedPowerPlantIndex < 0 && highestBidSoFar >= 3) || (biddedPowerPlantIndex >= 0 && highestBidSoFar < 3) ) {
        // throw some exception // TODO
    }
    
    int smallestNumberedPowerPlantOwned = 51;
    int indexOfSmallestNumberedPowerPlantOwned = -1;
    std::vector<PowerPlant*> ppsOwned = player->getPowerPlants();
    for(int i = 0; i < ppsOwned.size(); i++) {
        if(ppsOwned.at(i)->getCardNumber() < smallestNumberedPowerPlantOwned) {
            smallestNumberedPowerPlantOwned = ppsOwned.at(i)->getCardNumber();
            indexOfSmallestNumberedPowerPlantOwned = i;
        }
    }
    
    
    std::vector<PowerPlant> presentMarket = PowerPlant::peekPresentPowerPlantMarket();
    
    int ppIndex = -1;
    if(biddedPowerPlantIndex < 0) { // if no power plant was bid on
        srand(time(0));
        ppIndex = rand() % presentMarket.size();
        
        if( biddedPowerPlantIndex && player->getTotalWallet() >= presentMarket.at(ppIndex).getCardNumber() && presentMarket.at(ppIndex).getCardNumber() > smallestNumberedPowerPlantOwned ) {
            srand(time(0));
            int zeroOrOne = rand() % 2;
            
            if( zeroOrOne == 0) { // ~50% chance
                if( player->getNumPPOwned() == 3 ) { // if 3 pps ARE already owned (by passed player)
                    return BiddingDetails( PowerPlant::peekIthPowerPlantInPresentMarket(ppIndex).getCardNumber(), PowerPlant::peekIthPowerPlantInPresentMarket(ppIndex),PowerPlant::peekIthPowerPlantInPresentMarket(indexOfSmallestNumberedPowerPlantOwned) );
                }
                else { // if 3 pps are NOT already owned (by passed player)
                    return BiddingDetails( PowerPlant::peekIthPowerPlantInPresentMarket(ppIndex).getCardNumber(), PowerPlant::peekIthPowerPlantInPresentMarket(ppIndex),PowerPlant::peekIthPowerPlantInPresentMarket(ppIndex) );
                }
            }
        }
    }
    else { // if a pp WAS bid on already
        srand(time(0));
        int zeroOrOne = rand() % 2;
        if( zeroOrOne == 0 && player->getTotalWallet() >= highestBidSoFar+1) { // ~50% chance
            if( player->getNumPPOwned() == 3 ) { // if 3 pps ARE already owned (by passed player)
                return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),*ppsOwned.at(indexOfSmallestNumberedPowerPlantOwned) );
            }
            else { // if 3 pps are NOT already owned (by passed player)
                return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex) );
            }
        }
    }
    
    return BiddingDetails( -1,PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) );
}

std::vector<int> ModerateStrategy::getCityBuildingChoice() { // returns a vector of city numbers (a.k.a. map vertice numbers) // TODO
    std::vector<int> citiesToBuildIn;
    
    return citiesToBuildIn;
}
