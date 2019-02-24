
#include <GameStateIO.hpp>

namespace GameStateIO {
    
    namespace {
        
        bool containsSubstring(std::string str, std::string subStr) {
            
            if( str.find(subStr) != std::string::npos) { // that is, if the substring is found in the main string
                return true;
            }
            else {
                
                return false;
            }
        }
    }
    
    void readXmlFile(std::string filename) {
        // TODO
    }
    void writeXmlFile(std::string filename) {
        // TODO
    }
}
