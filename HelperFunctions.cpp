
#include <string>
#include "HelperFunctions.hpp"

namespace HelperFunctions {
    
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
}
