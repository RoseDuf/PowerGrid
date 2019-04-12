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
    
    if( player->getTotalCoalStockable() == player->getTotalCoalStocked() && player->getTotalGarbageStockable() == player->getTotalGarbageStocked() && player->getTotalOilStockable() == player->getTotalOilStocked() && player->getTotalUraniumStockable() == player->getTotalUraniumStocked() && player->getTotalWallet() < averageElektroAmount ) { // if this player has enough resources to fully power pps and has less than avg player's elektros, then gets aggressive for buying best pp possible
        AggressiveStrategy aggressiveStrategy(backgroundInformation);
        aggressiveStrategy.getBiddingDetails(player, biddedPowerPlantIndex, highestBidSoFar);
    }
    else { // otherwise, pass
        return BiddingDetails( -1,PowerPlant::peekIthPowerPlantInPresentMarket(0),PowerPlant::peekIthPowerPlantInPresentMarket(0) );
    }
}

std::vector<City> ModerateStrategy::getCityBuildingChoice(const Player* player, int gameStep) {
    std::vector<City> citiesToBuildIn;
    
    return citiesToBuildIn;
}
