#include "Strategy.hpp"
#include "HelperFunctions.hpp"

using namespace HelperFunctions;


Strategy::Strategy(AIStrategyData backgroundInformation) : backgroundInformation(backgroundInformation) {}

std::string Strategy::chooseOneRegion(std::vector<std::string> alreadyChosenRegions) {
    
    int amountOfPlayers = std::get<1>(this->backgroundInformation).size();
    
    int amountOfRegionsThatNeedToBeChosen = 0;
    if(amountOfPlayers == 2) {
        amountOfRegionsThatNeedToBeChosen = 3;
    }
    else if(amountOfPlayers == 3) {
        amountOfRegionsThatNeedToBeChosen = 3;
    }
    else if(amountOfPlayers == 4) {
        amountOfRegionsThatNeedToBeChosen = 4;
    }
    else if(amountOfPlayers == 5) {
        amountOfRegionsThatNeedToBeChosen = 5; 
    }
    else if(amountOfPlayers == 6) {
        amountOfRegionsThatNeedToBeChosen = 5; 
    }
    
    if( !(alreadyChosenRegions.size() < amountOfRegionsThatNeedToBeChosen) ) {
        // throw some exception
    }
    
    GraphBuilder* graph = std::get<2>(this->backgroundInformation);
    const std::vector<std::string> ALL_REGION_COLORS = graph->getAllRegionColors();
    std::vector<std::string> remainingRegionsToChooseFrom = ALL_REGION_COLORS;
    /*bool found = false;
    for(int i = 0; i < ALL_REGION_COLORS.size(); i++) {
    
        for(int j = 0; j < alreadyChosenRegions.size(); j++) {
        
            if( ALL_REGION_COLORS.at(i) == alreadyChosenRegions.at(j) ) {
                found = true;
                break;
            }
        }
        
        if( found == false ) {
            remainingRegionsToChooseFrom.push_back( ALL_REGION_COLORS.at(i) );
        }
        found = false;
    }*/
    
    for(auto it = remainingRegionsToChooseFrom.begin(); it != remainingRegionsToChooseFrom.end(); it++) {
        for(int j = 0; j < alreadyChosenRegions.size(); j++) {
            if( *it == alreadyChosenRegions.at(j) ) {
                remainingRegionsToChooseFrom.erase(it);
                break;
            }
        }
    }
    
    while( !remainingRegionsToChooseFrom.empty() ) {
        int i = rand() % remainingRegionsToChooseFrom.size();
        
        std::vector<std::string> tempSingleElementVector;
        tempSingleElementVector.push_back( remainingRegionsToChooseFrom.at(i) );
        
        remainingRegionsToChooseFrom.erase(remainingRegionsToChooseFrom.begin()+i);
        
        if( graph->areChosenRegionsConnected(combineVectors(remainingRegionsToChooseFrom,tempSingleElementVector))  ) {
            return remainingRegionsToChooseFrom.at(i);
        }
    }
    
//     srand(time(0));
//     int choice = rand() % graph->getAllRegionColors().size();
    
//     while( !graph->areChosenRegionsConnected(totalChoices) ) {
//         
//     }
    return ""; // TODO?
}
        //virtual std::string chooseRemainingRegions(std::vector<std::string> alreadyChosenRegions);

Strategy::~Strategy() {}
