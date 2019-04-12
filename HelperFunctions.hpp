
#ifndef HELPERFUNCTIONS_HPP_
#define HELPERFUNCTIONS_HPP_

#include <vector>
#include "Elektro.hpp"
#include "Player.hpp"
#include "Market.hpp"


namespace HelperFunctions {
    
    int min(int firstInteger, int secondInteger);
    
    int howManyCitiesCorrespondToStepTwoTriggering(int amountOfPlayers);
    
    Elektro integerToElektro(int elektroAmount);
    
    bool containsSubstring(std::string str, std::string subStr);
    
    std::string trim(const std::string str);
    
    std::string chopStr( std::string str, int beg, int end); // chop off parts before beg and after end
    
    std::string reverseStr(std::string str);
    
    std::string toLowerCase(std::string str);
    
    std::string toUpperCase(std::string str);
    
    bool equalsIgnoreCase(std::string str1, std::string str2);
    
    int howManyCitiesCorrespondToStepTwoTriggering(int amountOfPlayers);
    
    int howManyMoreCitiesUntilStepTwoIsTriggered(const Player* player, int amountOfPlayers);
    
    bool hasStepTwoBeenTriggered(std::vector<const Player*> players);
    
    int determineCostOfPurchasingCity(int amountOfPlayersAlreadyOccupyingCity); // assumes valid input
    
    int determineAmountOfCitiesOwnedByOtherPlayerWithLeastAmountOfCities(const Player* thisPlayer, std::vector<Player*> players);
    
    int determineAverageElektroAmountOfPlayers(std::vector<Player*> players);
    
    bool areDifferentPlayers(const Player* player1, const Player* player2);
    
    int determineAverageAmountOfCitiesOwnedByPlayers(std::vector<Player*> players);
    
    std::string determineCheapestResource(Market market, std::string resource1, std::string resource2); // if prices are same, the first resource passed as a parameter is returned
    
    std::string determineCheapestResource(Market market, std::string resource1, std::string resource2, std::string resource3, std::string resource4); // if prices are same, the first resource passed as a parameter is returned
    
    template<typename T> std::vector<T> combineVectors(std::vector<T> v1, std::vector<T> v2) {
        std::vector<T> combination;
        for(int i = 0; i < v1.size(); i++) {
            combination.push_back( v1.at(i) );
        }
        for(int i = 0; i < v2.size(); i++) {
            combination.push_back( v2.at(i) );
        }
        
        return combination;
    }
}

#endif
