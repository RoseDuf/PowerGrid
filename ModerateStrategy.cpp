#include "ModerateStrategy.hpp"
#include "HelperFunctions.hpp"
#include "AggressiveStrategy.hpp"

using namespace HelperFunctions;

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
    
    std::vector<Player*> players = std::get<1>(backgroundInformation);
    int averageElektroAmount = determineAverageElektroAmountOfPlayers(players);
    
    if( player->getTotalCoalStockable() == 2*player->getTotalCoalStocked() && player->getTotalGarbageStockable() == 2*player->getTotalGarbageStocked() && player->getTotalOilStockable() == 2*player->getTotalOilStocked() && player->getTotalUraniumStockable() == 2*player->getTotalUraniumStocked() && player->getTotalWallet() < averageElektroAmount ) { // if this player has enough resources to fully power pps and has less than avg player's elektros, then gets aggressive for buying best pp possible
        AggressiveStrategy aggressiveStrategy(backgroundInformation);
        aggressiveStrategy.getBiddingDetails(player, biddedPowerPlantIndex, highestBidSoFar);
    }
    else { // otherwise, pass
        return BiddingDetails( -1,PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) );
    }
}

std::vector<City> ModerateStrategy::getCityBuildingChoice(const Player* player, int gameStep) {
    
    std::vector<Player*> players = std::get<1>(backgroundInformation);
    
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
        
    if(gameStep == 1) {
        // avoid triggering step 2 (as assignment 3 instructions state)
        int costsAccumulatedSoFar = 0;
        int citiesBeingPurchasedSoFar = 0;
        for(auto it = costsAndStillOccupiablePairsIndices.begin(); it != costsAndStillOccupiablePairsIndices.end(); it++) {
            costsAccumulatedSoFar += it->first;
            citiesBeingPurchasedSoFar++;
            
            if( player->getTotalWallet() >= costsAccumulatedSoFar && player->getNumCitiesOwned()+citiesBeingPurchasedSoFar < howManyCitiesCorrespondToStepTwoTriggering(players.size()) ) {
                citiesToBuildIn.push_back( stillOccupiablePairs.at(it->second).first );
            }
            else {
                break;
            }
        }
    }
    else {
        // chase the average number of cities built
        int costsAccumulatedSoFar = 0;
        int citiesBeingPurchasedSoFar = 0;
        for(auto it = costsAndStillOccupiablePairsIndices.begin(); it != costsAndStillOccupiablePairsIndices.end(); it++) {
            costsAccumulatedSoFar += it->first;
            citiesBeingPurchasedSoFar++;
            
            if( player->getTotalWallet() >= costsAccumulatedSoFar && player->getNumCitiesOwned()+citiesBeingPurchasedSoFar <= determineAverageAmountOfCitiesOwnedByPlayers(players) ) {
                citiesToBuildIn.push_back( stillOccupiablePairs.at(it->second).first );
            }
            else {
                break;
            }
        }
    }
    
    return citiesToBuildIn;
}

ResourcePurchaseChoice ModerateStrategy::getResourcePurchaseChoice(const Player* player) {
    return ResourcePurchaseChoice(0,0,0,0); // TODO
}
