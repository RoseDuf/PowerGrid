
#include "AggressiveStrategy.hpp"
#include "HelperFunctions.hpp"

using namespace HelperFunctions;

AggressiveStrategy::AggressiveStrategy(AIStrategyData backgroundInformation) : Strategy(backgroundInformation) {}

BiddingDetails AggressiveStrategy::getBiddingDetails(const Player* player, int biddedPowerPlantIndex, int highestBidSoFar) {
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
            if( player->getTotalWallet() >= presentPowerPlantMarket.at(i).getCardNumber() ) {
                if( player->getNumPPOwned() == 3 ) { // if 3 pps ARE already owned (by passed player)
                    return BiddingDetails( presentPowerPlantMarket.at(i).getCardNumber(),presentPowerPlantMarket.at(i),*ppsOwned.at(smallestNumberedPowerPlantOwned) ); // int bid amount, PowerPlant powerPlantBeingBiddedOn
                }
                else { // if 3 pps are NOT already owned (by passed player)
                    return BiddingDetails( presentPowerPlantMarket.at(i).getCardNumber(),presentPowerPlantMarket.at(i),presentPowerPlantMarket.at(i) ); // int bid amount, PowerPlant powerPlantBeingBiddedOn
                }
            }
        }
    }
    else { // if a power plant WAS chosen to be bid on
        //return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInPresentMarket(biddedPowerPlantIndex) );
        if( player->getNumPPOwned() == 3 ) { // if 3 pps ARE already owned (by passed player)
            return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex),*ppsOwned.at(smallestNumberedPowerPlantOwned) ); // int bid amount, PowerPlant powerPlantBeingBiddedOn
        }
        else { // if 3 pps are NOT already owned (by passed player)
            return BiddingDetails( highestBidSoFar+1,PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex),PowerPlant::peekIthPowerPlantInFutureMarket(biddedPowerPlantIndex) ); // int bid amount, PowerPlant powerPlantBeingBiddedOn
        }
    }
        
    return BiddingDetails( -1,PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) ); // if nothing else was returned, return -1, which means that no bid was made (the 2nd parameter's PowerPlant is irrelevant and could be any PowerPlant)
}

std::vector<City> AggressiveStrategy::getCityBuildingChoice(const Player* player, int gameStep) {
    std::vector<City> citiesToBuildIn;
    
    GraphBuilder* graph = std::get<2>(backgroundInformation);
    
    std::vector< std::pair<City,int> > stillOccupiablePairs = graph->getStillOccupiableCitiesAndOccupationAmounts(gameStep);
    std::vector<City> co = player->getCitiesOwned();
    
    std::map<int,int> costsAndStillOccupiablePairsIndices;
    
    for(int i = 0; i < stillOccupiablePairs.size(); i++) {
        for(int j = 0; j < co.size(); j++) {
            if( stillOccupiablePairs.at(i).first.getCityName() != co.at(j).getCityName() ) {
                int currentCityCost = determineCostOfPurchasingCity(stillOccupiablePairs.at(i).second);
                int currentPathCost = graph->CostFromOneCityToAnother(stillOccupiablePairs.at(i).first.getCityName(),co.at(j).getCityName());
                int currentPathPlusCityCost =  currentCityCost + currentPathCost;
                costsAndStillOccupiablePairsIndices.insert( std::make_pair(currentPathPlusCityCost, i) );
            }
        }
    }
    
    int costsAccumulatedSoFar = 0;
    int citiesBeingPurchasedSoFar = 0;
    for(auto it = costsAndStillOccupiablePairsIndices.begin(); it != costsAndStillOccupiablePairsIndices.end(); it++) {
        costsAccumulatedSoFar += it->first;
        citiesBeingPurchasedSoFar++;
        
        if( player->getTotalWallet() >= costsAccumulatedSoFar && player->getNumCitiesOwned()+citiesBeingPurchasedSoFar <= player->getCurrentTotalMaximumCityPoweringPotential()+1 ) {
            citiesToBuildIn.push_back( stillOccupiablePairs.at(it->second).first );
        }
        else {
            break;
        }
    }
    
    return citiesToBuildIn;
}

ResourcePurchaseChoice AggressiveStrategy::getResourcePurchaseChoice(const Player* player) {
    return ResourcePurchaseChoice(0,0,0,0); // TODO
}
