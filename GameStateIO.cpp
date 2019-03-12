
#include "GameStateIO.hpp"

#include <iostream>

#include <fstream>

#include "XmlDocumentTree.hpp"

#include "HelperFunctions.hpp"

#include <vector>

#include "Elektro.hpp"

#include "PowerPlant.h"

using namespace HelperFunctions;
using namespace std;

namespace GameStateIO {
    
    namespace {
        
        int generateInt(XmlDocumentNode* node) {
            return std::stoi( trim(node->getNodeValue()) );
        }
        
        std::string generateString(XmlDocumentNode* node) {
            return node->getNodeValue(); // no trimming, just in case whitespace is desired (which shouldn't cause any problem anyways)
        }
        
        Elektro generateElektro(XmlDocumentNode* node) {
        	
	        std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
        
        	int bill1Quantity = -1;
	        int bill10Quantity = -1;
            int bill50Quantity = -1;
        
	        for(auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
	            if( equalsIgnoreCase( (*it)->getNodeName(), "bill1Quantity" ) ) {
        	        bill1Quantity = generateInt( ((*it)->getChildNodes()).front() );
	            }
	            else if( equalsIgnoreCase( (*it)->getNodeName(), "bill10Quantity" ) ) {
        	        bill10Quantity = generateInt( ((*it)->getChildNodes()).front() );
	            }
	            else if( equalsIgnoreCase( (*it)->getNodeName(), "bill50Quantity" ) ) {
        	        bill50Quantity = generateInt( ((*it)->getChildNodes()).front() );
	            }
	        }
        
	        Elektro generatedElektro = Elektro( bill1Quantity, bill10Quantity, bill50Quantity );
            return generatedElektro;
	    }
        
        bool isValue(std::string str) {
            bool tempBool = str.find("<") == string::npos; // if there is no position for <, then it's a value (not other set of nested tags)
            return tempBool;
        }
        
        std::vector< std::pair<std::string,std::string> > getChildren(std::string parentElementName, std::string parentAndItsChildren) {
            
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            
            std::vector< std::pair<std::string,std::string> > nameAndTagPairs; // each child is given from opening tag to closing tag, along with its name
            
            std::string itsChildren = chopStr( parentAndItsChildren, 1+parentElementName.size()+1, (parentAndItsChildren.size()-1)-(2+parentElementName.size()+1) );
            
            if( isValue(itsChildren) ) {
                std::pair<std::string,std::string> yo;
                yo.first = ""; // no element name, since it's a value
                yo.second = trim(itsChildren);
                nameAndTagPairs.push_back(yo);
                return nameAndTagPairs;
            }
            
            while( d < itsChildren.size()-1 )  { // while the previous end index of itsChildren is not reached
                
                std::pair<std::string, std::string> currentPair;
                
                a = itsChildren.find("<", d);
                b = itsChildren.find(">", a);
                currentPair.first = chopStr(itsChildren, a+1, b-1); // the child's element name only
                
                c = itsChildren.find("</"+currentPair.first+">", b);
                d = itsChildren.find(">", c);
                currentPair.second = chopStr(itsChildren, a, d); // the child from opening to closing tag (including anything nested within it)
                
                nameAndTagPairs.push_back(currentPair);
            }
            
            return nameAndTagPairs;
        }
        
        XmlDocumentNode* recursiveXmlParser(std::string parentElementName, std::string totalStr) {
            
            XmlDocumentNode* parentNode = new XmlDocumentNode("placeholder1","placeholder2");
            
            std::vector< std::pair<std::string,std::string> > children = getChildren(parentElementName,totalStr);
            
            if( children.size() == 1 && isValue(children.at(0).second) ) {
                XmlDocumentNode* childNode = new XmlDocumentNode(children.at(0).first, children.at(0).second);
                parentNode = new XmlDocumentNode(parentElementName, "");
                parentNode->addChildNode(childNode);
            }
            else {
                parentNode = new XmlDocumentNode(parentElementName,"");
                for(int i = 0; i < children.size(); i++) {
                    parentNode->addChildNode( recursiveXmlParser(children.at(i).first,children.at(i).second) );
                }
            }
            
            return parentNode;
        }
        
        XmlDocumentTree* xmlParser(std::string parentElementName, std::string totalStr) {
            
            return new XmlDocumentTree( recursiveXmlParser(parentElementName,totalStr) );
        }
        
        City generateCity(XmlDocumentNode* node) {
            
            std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
            
            int verticeNumber;
            std::string cityName;
            std::string cityColor;
            
            for (auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
                if( (*it)->getNodeName() == "verticeNumber" ) {
                    verticeNumber = generateInt( ((*it)->getChildNodes()).front() );
                }
                else if( (*it)->getNodeName() == "cityName" ) {
                    cityName = generateString( ((*it)->getChildNodes()).front() );
                }
                else if( (*it)->getNodeName() == "cityColor" || (*it)->getNodeName() == "cityColour" ) {
                    cityColor = generateString( ((*it)->getChildNodes()).front() );
                }
            }
            
            City generatedCity = City( verticeNumber, cityName, cityColor );
            return generatedCity;
        }
        
        EdgeTriplet generateEdgeTriplet(XmlDocumentNode* node) {
            
            std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
            
            City city1;
            City city2;
            int edgeCost;
            bool firstCityEncountered = false;
            
            for (auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
                if( (*it)->getNodeName() == "City" && firstCityEncountered == false ) {
                    city1 = generateCity(*it);
                    firstCityEncountered = true;
                }
                else if( (*it)->getNodeName() == "City" && firstCityEncountered == true ) {
                    city2 = generateCity(*it);
                }
                else if( (*it)->getNodeName() == "edgeCost" ) {
                    edgeCost = generateInt( ((*it)->getChildNodes()).front() );
                }
            }
            
            EdgeTriplet generatedEdgeTriplet = EdgeTriplet( city1, city2, edgeCost );
            return generatedEdgeTriplet;
        }
        
        PowerPlant generatePowerPlant( XmlDocumentNode* node ) {
            
            std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
            
            int cardNumber = 0;
            int numOfCitiesPowered = 0;
            int numResourcesTokensNeeded = 0;
            std::string resourceTokenNeeded1 = "";
            std::string resourceTokenNeeded2 = "";
            
            for(auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
                if( equalsIgnoreCase( (*it)->getNodeName(), "cardnumber" ) ) {
                    cardNumber = generateInt( ((*it)->getChildNodes()).front() );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "numOfCitiesPowered" ) ) {
                    numOfCitiesPowered = generateInt( ((*it)->getChildNodes()).front() );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "numResourcesTokensNeeded" ) {
                    numOfCitiesPowered = generateInt( ((*it)->getChildNodes()).front() );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "resourceTokenNeeded1" ) ) {
                    resourceTokenNeeded1 = generateString( ((*it)->getChildNodes()).front() );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "resourcetokenneeded2" ) ) {
                    resourceTokenNeeded2 = generateString( ((*it)->getChildNodes()).front() );
                }
            }
        
            PowerPlant generatedPowerPlant = PowerPlant(cardNumber, numOfCitiesPowered, numResourcesTokensNeeded, resourceTokenNeeded1, resourceTokenNeeded2);
            
            return generatedPowerPlant;
        }
        
        Player generatePlayer(XmlDocumentNode* node) {/*
            std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
            std::string playerName = "";
            std::string playerColor = "";
            Elektro elektro;
            std::vector<City> citiesOwned;
            std::vector<PowerPlant> powerPlants;
            
            for(auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
                if( toLowerCase((*it)->getNodeName()) == "playername" ) {
                    playerName = generateString( ((*it)->getChildNodes()).front() );
                }
                else if( toLowerCase((*it)->getNodeName()) == "playercolor" || toLowerCase((*it)->getNodeName()) == "playercolour" ) {
                    playerColor = generateString( ((*it)->getChildNodes()).front() );
                }
                else if( toLowerCase((*it)->getNodeName()) == "elektro" ) {
                    elektro = generateElektro(*it);
                }
                else if( toLowerCase((*it)->getNodeName()) == "powerplant" ) {
                    powerPlants.push_back( generatePowerPlant(*it) );
                }
                else if( toLowerCase((*it)->getNodeName()) == "resourcetokensXYZ"XYZ ) {
                    resourceXYZ
                }
                else if( toLowerCase((*it)->getNodeName()) == "city" ) {
                    citiesOwned.push_back( generateCity(*it) );
                }
            }
            
            Player generatedPlayer = Player( playerName, playerColor );
            
            generatedPlayer.collectElektro( elektro.getBillAmmount(1), elektro.getBillAmmount(10), elektro.getBillAmmount(50) );
            
            
            for(int i = 0; i < powerPlants.size(); i++) {
                generatedPlayer.addPowerPlant( powerPlants.at(i) );
            }
            
            return generatedPlayer;*/
            return Player();// TODO
        }
        
        GameState generateGameState(XmlDocumentNode* node) {
            std::list<XmlDocumentNode*> theChildren = node->getChildNodes();
            std::vector<City> citiesOwned;
            std::vector<EdgeTriplet> edgeTriplets;
            std::vector<Player> players;
            int turnOfPlayer = 0;

            for (auto it = theChildren.cbegin(); it != theChildren.cend(); it++) {
                if( equalsIgnoreCase( (*it)->getNodeName(), "turnOfPlayer" ) ) {
                    turnOfPlayer = generateInt( ((*it)->getChildNodes()).front() );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "City" ) ) {
                    citiesOwned.push_back( generateCity(*it) );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "edgeTriplet" ) ) {
                    edgeTriplets.push_back( generateEdgeTriplet(*it) );
                }
                else if( equalsIgnoreCase( (*it)->getNodeName(), "Player" ) ) {
                    players.push_back( generatePlayer(*it) );
                }
            }

            return GameState( turnOfPlayer, citiesOwned, edgeTriplets,  players ); // I need to make a constructor that’s something like this
        }
        
        GameState generateGameState(XmlDocumentTree* tree) {
            
            GameState generatedGameState = generateGameState( tree->getRootNode() );
            return generatedGameState;
        }
    }
    
    GameState readXmlFile(std::string filename) {
        
        std::ifstream myfile(filename);
        std::string fileAsOneLinerString = "";
        std::string currentLine = "";
        while( getline(myfile, currentLine) ) {
            fileAsOneLinerString += trim(currentLine);
        }
        
        // these next 11 lines r just for testing the getChildren function
//         std::cout << fileAsOneLinerString << std::endl;
//         std::vector< std::pair<std::string,std::string> > theChildren = getChildren("GameState", fileAsOneLinerString);
//         for(int i = 0; i < theChildren.size(); i++) {
//             std::cout << theChildren.at(i).first << std::endl;
//             std::cout << theChildren.at(i).second << std::endl;
//         }
//         std::vector< std::pair<std::string,std::string> > theKids = getChildren("turnOfPlayer", "<turnOfPlayer>2</turnOfPlayer>");
//         for(int i = 0; i < theKids.size(); i++) {
//             std::cout << theKids.at(i).first << std::endl;
//             std::cout << theKids.at(i).second << std::endl;
//         }
        
        
        // some testing of recursiveXmlParser function
//         XmlDocumentTree* tree = xmlParser("GameState", fileAsOneLinerString);
//         XmlDocumentNode* rootNode = tree->getRootNode();
//         std::cout << "Root node: " << rootNode->getNodeName() << std::endl;
//         std::list<XmlDocumentNode*> children = rootNode->getChildNodes();
//         std::cout << "name: " << children.front()->getNodeName() << std::endl;
//         std::cout << "value: " << children.front()->getNodeValue() << std::endl;
//         std::list<XmlDocumentNode*> grandchildren = children.front()->getChildNodes();
//         std::cout << "name: " << grandchildren.front()->getNodeName() << std::endl;
//         std::cout << "value: " << grandchildren.front()->getNodeValue() << std::endl;
        
        
        
        GameState generatedGameState = generateGameState( xmlParser("GameState", fileAsOneLinerString) );
//         std::vector<City> cities = generatedGameState.getCities();
//         std::vector<EdgeTriplet> edgeTriplets = generatedGameState.getEdgeTriplets();
        //PowerPlant powerPlant = generatedGameState.getPlayers().at(0).getPowerPlants().at(0);
        return generatedGameState;
    }
    
    void writeXmlFile(std::string filename) {
        // TODO
    }
}
