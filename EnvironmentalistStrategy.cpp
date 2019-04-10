#include "EnvironmentalistStrategy.hpp"
#include "PowerPlant.hpp"

EnvironmentalistStrategy::EnvironmentalistStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

BiddingDetails EnvironmentalistStrategy::getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
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
    
    if( biddedPowerPlantIndex < 0) { // if no power plant was chosen to be bid on
        std::vector<PowerPlant> presentPowerPlantMarket = PowerPlant::peekPresentPowerPlantMarket();
        
        for(int i = presentPowerPlantMarket.size()-1; i >= 0; i--) {
            if( presentPowerPlantMarket.at(i).isGreen() && player->getTotalWallet() >= presentPowerPlantMarket.at(i).getCardNumber() && presentPowerPlantMarket.at(i).getCardNumber() > smallestNumberedPowerPlantOwned ) {
                if( smallestNumberedPowerPlantOwned < 51 ) { // if pp IS already owned (by passed player)
                    return BiddingDetails( presentPowerPlantMarket.at(i).getCardNumber(),presentPowerPlantMarket.at(i),*ppsOwned.at(indexOfSmallestNumberedPowerPlantOwned) );
                }
                else { // if pp is NOT already owned (by passed player)
                    return BiddingDetails( presentPowerPlantMarket.at(i).getCardNumber(),presentPowerPlantMarket.at(i),presentPowerPlantMarket.at(i) );            
                }
            }
        }
        
        // if the following if statement is reached, then all the power plants in the present market are not green / environmentally friendly
        if( player->getTotalWallet() >= PowerPlant::peekIthPowerPlantInPresentMarket(0).getCardNumber() && player->getNumPPOwned() < 3 && PowerPlant::peekIthPowerPlantInFutureMarket(0).getCardNumber() > smallestNumberedPowerPlantOwned) {
            if(smallestNumberedPowerPlantOwned < 51) { // if pp IS already owned (by passed player)
                return BiddingDetails( PowerPlant::peekIthPowerPlantInPresentMarket(0).getCardNumber(), PowerPlant::peekIthPowerPlantInPresentMarket(0),*ppsOwned.at(smallestNumberedPowerPlantOwned) );
            }
            else { // if pp is NOT already owned (by passed player)
                return BiddingDetails( PowerPlant::peekIthPowerPlantInPresentMarket(0).getCardNumber(), PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) );
            }
        }
    }
    else { // if a power plant WAS chosen to be bid on
        
        if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).isGreen() ) {
            if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).getCardNumber() > smallestNumberedPowerPlantOwned ) {
                
                if(smallestNumberedPowerPlantOwned < 51) { // if pp IS already owned (by passed player)
                    return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),PowerPlant::peekIthPowerPlantInPresentMarket(smallestNumberedPowerPlantOwned) );
                }
                else { // if pp is NOT already owned (by passed player)
                    return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex) );
                }
            }
        }
        else { // if is not green
            if( PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex).getCardNumber() > smallestNumberedPowerPlantOwned ) {
                srand(time(0));
                int chance = rand() % 5;
            
                if(chance == 0) { // ~1/5 = 20% chance
                    if(smallestNumberedPowerPlantOwned < 51) { // if pp IS already owned (by passed player)
                        return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),*ppsOwned.at(smallestNumberedPowerPlantOwned) );
                    }
                    else { // if pp is NOT already owned (by passed player)
                        return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex),PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex) );
                    }
                }
            }
        }
    }
        
    return BiddingDetails( -1,PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) ); // if nothing else was returned, return -1, which means that no bid was made (the 2nd parameter's PowerPlant is irrelevant and could be any PowerPlant)
}
