
#include <string>
#include "HelperFunctions.hpp"
#include "Elektro.hpp"
#include <vector>

namespace HelperFunctions {
    
    bool hasStepTwoBeenTriggered(std::vector<const Player*> players) {
        
        int stepTwoAmount = howManyCitiesCorrespondToStepTwoTriggering( players.size() );
        
        for(int i = 0; i < players.size(); i++) {
            if( players.at(i)->getNumCitiesOwned() >= stepTwoAmount ) {
                return true;
            }
        }
        
        return false;
    }
    
    int howManyMoreCitiesUntilStepTwoIsTriggered(const Player* player, int amountOfPlayers) {
        return howManyCitiesCorrespondToStepTwoTriggering(amountOfPlayers) - player->getNumCitiesOwned();
    }
    
    int howManyCitiesCorrespondToStepTwoTriggering(int amountOfPlayers) {
        
        switch(amountOfPlayers) {
            case 2: {
                return 10;
            }
            case 3: {
                return 7;
            }
            case 4: {
                return 7;
            }
            case 5: {
                return 7;
            }
            case 6: {
                return 6;
            }
            default: {
                // throw some exception
            }
        }
        
        return -1;
    }
    
    Elektro integerToElektro(int elektroAmount) {
        int amountOfOnes = 0;
        int amountOfTens = 0;
        int amountOfFifties = 0;
        
        while(elektroAmount >= 50) {
            amountOfFifties++;
            elektroAmount-=50;
        }
        
        while(elektroAmount >= 10) {
            amountOfTens++;
            elektroAmount-=10;
        }
        
        while(elektroAmount >= 1) {
            amountOfOnes++;
            elektroAmount--;
        }
        
        return Elektro(amountOfOnes, amountOfTens, amountOfFifties);
    }
    
    std::string reverseStr(std::string str) {
        
        std::string reversedStr = "";
        
        for(int i = 0; i < str.size(); i++) {
            reversedStr = str.at(i) + reversedStr;
        }
        
        return reversedStr;
    }
    
    bool containsSubstring(std::string str, std::string subStr) {
        
        if( str.find(subStr) != std::string::npos ) { // that is, if the substring is found in the main string
            return true;
        }
        else {
            
            return false;
        }
    }
    
    std::string trim(const std::string str) {
        
        // Remove whitespace from left side of leftmost non-whitespace character
        int leftBeginningIndex = 0;
        for(int i = 0; i < str.size(); i++) {
            
            if( str.at(i) != ' ' && str.at(i) != '\t' && str.at(i) != '\n' && str.at(i) != '\r' ) {
                leftBeginningIndex = i;
                break;
            }
        }
        
        // Remove whitespace from right side of rightmost non-whitespace character, and then copy the rest of the characters
        std::string trimmedStr = "";
        bool regularCharEncountered = false;
        for(int j = str.size()-1; j >= leftBeginningIndex; j--) {
            
            if( str.at(j) != ' ' && str.at(j) != '\t' && str.at(j) != '\n' && str.at(j) != '\r' ) { // if regular char encountered (regular = non-whitespace)
                trimmedStr = str.at(j) + trimmedStr;
                regularCharEncountered = true;
            }
            if( regularCharEncountered == true && (str.at(j) == ' ' || str.at(j) == '\t' || str.at(j) == '\n' || str.at(j) == '\r') ) {
                trimmedStr = str.at(j) + trimmedStr;
            }
        }
        
        return trimmedStr;
    }
    
    std::string chopStr( std::string str, int beg, int end) { // chop off parts before beg and after end
        
        std::string tempStr = str.substr(beg, end-beg+1);
        return tempStr;
    }
    
    std::string toLowerCase(std::string str) {
        
        std::string resultStr = "";
        
        for(int i = 0; i < str.size(); i++) {
            switch( str.at(i) ) {
                case 'A' : {
                    resultStr += "a";
                    break;
                }
                case 'B' : {
                    resultStr += "b";
                    break;
                }
                case 'C' : {
                    resultStr += "c";
                    break;
                }
                case 'D' : {
                    resultStr += "d";
                    break;
                }
                case 'E' : {
                    resultStr += "e";
                    break;
                }
                case 'F' : {
                    resultStr += "f";
                    break;
                }
                case 'G' : {
                    resultStr += "g";
                    break;
                }
                case 'H' : {
                    resultStr += "h";
                    break;
                }
                case 'I' : {
                    resultStr += "i";
                    break;
                }
                case 'J' : {
                    resultStr += "j";
                    break;
                }
                case 'K' : {
                    resultStr += "k";
                    break;
                }
                case 'L' : {
                    resultStr += "l";
                    break;
                }
                case 'M' : {
                    resultStr += "m";
                    break;
                }
                case 'N' : {
                    resultStr += "n";
                    break;
                }
                case 'O' : {
                    resultStr += "o";
                    break;
                }
                case 'P' : {
                    resultStr += "p";
                    break;
                }
                case 'Q' : {
                    resultStr += "q";
                    break;
                }
                case 'R' : {
                    resultStr += "r";
                    break;
                }
                case 'S' : {
                    resultStr += "s";
                    break;
                }
                case 'T' : {
                    resultStr += "t";
                    break;
                }
                case 'U' : {
                    resultStr += "u";
                    break;
                }
                case 'V' : {
                    resultStr += "v";
                    break;
                }
                case 'W' : {
                    resultStr += "w";
                    break;
                }
                case 'X' : {
                    resultStr += "x";
                    break;
                }
                case 'Y' : {
                    resultStr += "y";
                    break;
                }
                case 'Z' : {
                    resultStr += "z";
                    break;
                }
                default : {
                    resultStr += str.at(i);
                    break;
                }
            }
        }
        
        return resultStr;
    }
    
    std::string toUpperCase(std::string str) {
        
        std::string resultStr = "";
        
        for(int i = 0; i < str.size(); i++) {
            switch( str.at(i) ) {
                case 'a' : {
                    resultStr += "A";
                    break;
                }
                case 'b' : {
                    resultStr += "B";
                    break;
                }
                case 'c' : {
                    resultStr += "C";
                    break;
                }
                case 'd' : {
                    resultStr += "D";
                    break;
                }
                case 'e' : {
                    resultStr += "E";
                    break;
                }
                case 'f' : {
                    resultStr += "F";
                    break;
                }
                case 'g' : {
                    resultStr += "G";
                    break;
                }
                case 'h' : {
                    resultStr += "H";
                    break;
                }
                case 'i' : {
                    resultStr += "I";
                    break;
                }
                case 'j' : {
                    resultStr += "J";
                    break;
                }
                case 'k' : {
                    resultStr += "K";
                    break;
                }
                case 'l' : {
                    resultStr += "L";
                    break;
                }
                case 'm' : {
                    resultStr += "M";
                    break;
                }
                case 'n' : {
                    resultStr += "N";
                    break;
                }
                case 'o' : {
                    resultStr += "O";
                    break;
                }
                case 'p' : {
                    resultStr += "P";
                    break;
                }
                case 'q' : {
                    resultStr += "Q";
                    break;
                }
                case 'r' : {
                    resultStr += "R";
                    break;
                }
                case 's' : {
                    resultStr += "S";
                    break;
                }
                case 't' : {
                    resultStr += "T";
                    break;
                }
                case 'u' : {
                    resultStr += "U";
                    break;
                }
                case 'v' : {
                    resultStr += "V";
                    break;
                }
                case 'w' : {
                    resultStr += "W";
                    break;
                }
                case 'x' : {
                    resultStr += "Y";
                    break;
                }
                case 'y' : {
                    resultStr += "Y";
                    break;
                }
                case 'z' : {
                    resultStr += "Z";
                    break;
                }
                default : {
                    resultStr += str.at(i);
                }
            }
        }
        
        return resultStr;
    }
    
    bool equalsIgnoreCase(std::string str1, std::string str2) {
        return toLowerCase(str1) == toLowerCase(str2);
    }
}
