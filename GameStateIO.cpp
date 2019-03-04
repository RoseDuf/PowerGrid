
#include "GameStateIO.hpp"

#include <iostream>

#include <fstream>

#include "XmlDocumentTree.hpp"

#include "HelperFunctions.hpp"

#include <vector>

using namespace HelperFunctions;
using namespace std;

namespace GameStateIO {
        
    namespace {
        
//         bool containsSiblingTagPair(std::string siblingTagPairs, std::string parentElementName) {
//             
//             bool tempBool = containsSubstring(siblingTagPairs, "<"+parentElementName+">");
//             return tempBool;
//         }
//         
//         std::string getLeadingSiblingTagPairString(std::string siblingsTotalStr, std::string elementName) {
//             
//             // Start and end indices OF SIBLING TO EXTRACT from siblingsTotalStr
//             int startIndex = siblingsTotalStr.find("<"+elementName+">");
//             int endIndex = siblingsTotalStr.find("</"+elementName+">")+string("</").size()+elementName.size();/* no +string(">").size(); because we want to include > */
//             
//             std::string tempStr = chopStr( siblingsTotalStr, startIndex, endIndex );
//             return tempStr;
//         }
//         
//         std::string getLeadingSiblingName(std::string siblingsTotalStr) {
//             int startIndex = siblingsTotalStr.find("<") + string("<").size();
//             int endIndex = siblingsTotalStr.find(">") - string(">").size();
//             
//             std::string tempStr = chopStr( siblingsTotalStr, startIndex, endIndex );
//             return tempStr;
//         }
//         
//         std::string resultingStringWithLeadSiblingRemoved(std::string siblingsTotalStr, std::string elementNameOfLeadSibling) {
//             
//             int a = siblingsTotalStr.find("<"+elementNameOfLeadSibling+">") + string("<").size() + siblingsTotalStr.size() + string(">").size();            
//             int b = siblingsTotalStr.find("</"+elementNameOfLeadSibling+">") - string("<").size();
//             std::string tempStr = chopStr(siblingsTotalStr, a, b);
//             
//            return tempStr;
//         }
//         
//         
//         std::string extractChildrenTagPairsString(std::string parentTagPairsContainingChildrenTagPairs, std::string elementNameOfParent) {
//             int a = parentTagPairsContainingChildrenTagPairs.find("<"+elementNameOfParent+">")
//             + string("<").size() + elementNameOfParent.size() + string(">").size();
//             
//             int b = parentTagPairsContainingChildrenTagPairs.find("</"+elementNameOfParent+">") - string("<").size();
//             
//             std::string tempStr = chopStr(parentTagPairsContainingChildrenTagPairs, a, b);
//             
//            return tempStr;
//         }
// 
//         bool isLoneTagPair(std::string totalStr, std::string elementName) { // for the current depth in the tree
//             std::string tempStr = chopStr( totalStr, 0+string("<").size(), totalStr.size()-1); // tempStr = totalStr with char at index 0 removed
//             bool tempBool = tempStr.find("<"+elementName+">") == string::npos; // if <elementName> cannot be found, then return true, as in it is a lone tag pair
//             return tempBool;
//         }
//         
//         bool hasNestedTagPair(std::string parentTagPairStr, std::string parentElementName) {
//             
//             int a = parentTagPairStr.find("<"+parentElementName+">")+string("<").size()+parentElementName.size()+string(">").size();
//             int b = parentTagPairStr.find("</"+parentElementName+">")-string("<").size();
//             
//             std::string stringWithinParentTagPair = chopStr(parentTagPairStr, a, b);
//             
//             bool tempBool = stringWithinParentTagPair.find("<") != string::npos; // if there is another opening angle bracket, then there's another one or more nested tag pairs
//             return tempBool;
//         }
//         
//         std::string extractValueFromLoneTagPair(std::string currentTotalStr) {
// 
//             std::string elementName = getLeadingSiblingName(currentTotalStr);
//             
//             int includedStartIndex = currentTotalStr.find("<") + string("<").size() + elementName.size() + string(">").size();
//             int includedEndIndex = currentTotalStr.find("</"+elementName+">") - string("<").size();
//             
//             std::string extractedValue = chopStr( currentTotalStr, includedStartIndex, includedEndIndex );
//             
//             return extractedValue;
//         }
//         
//         XmlDocumentNode* recursive(std::string totalStr) {
//             std::string parentElementName = chopStr( totalStr, 0+string("<").size(), totalStr.find(">")-string(">").size() );
//             XmlDocumentNode* currentNode = new XmlDocumentNode("","");
//             
//             if( isLoneTagPair(totalStr, parentElementName) && !hasNestedTagPair(totalStr, parentElementName) ) {
//                 
//                 currentNode = new XmlDocumentNode( parentElementName, extractValueFromLoneTagPair(totalStr) );
//             }
//             else {
//                 std::string childrenStr = extractChildrenTagPairsString(totalStr, parentElementName);;
//                 while( containsSiblingTagPair(childrenStr, parentElementName) ) {
//                     childrenStr = extractChildrenTagPairsString(totalStr, parentElementName);
//                     currentNode = new XmlDocumentNode(parentElementName, "");
//                     currentNode->addChildNode( recursive(getLeadingSiblingTagPairString(childrenStr, getLeadingSiblingName(childrenStr))) );
//                     childrenStr = resultingStringWithLeadSiblingRemoved(childrenStr, getLeadingSiblingName(childrenStr));
//                 }
//             }
//             
//             return currentNode;
//         }
    
        /*std::string getNextNameAndRemoveIt(std::string& totalStr) {
            
            int a = totalStr.find("<")+1; // first char after <
            int b = totalStr.find(">")-1; // first char before >
            
            std::string nextName = chopStr(totalStr, a, b);
            
            int c = nextName.size()+2; // one char after closing angle bracket of <elementName>
            int d = totalStr.find("</"+nextName+">")-1; // one char before opening angle bracket of </elementName>
            
            totalStr = chopStr(totalStr,c,d);
            
            return nextName;
        }*/
        
        //b4:
        /*XmlDocumentNode* recursive(std::string totalStr) {
            std::string name = getNextNameAndRemoveIt(totalStr);
            std::string value = "wtv";
            XmlDocumentNode* node = new XmlDocumentNode(name, value);
            
            return node;
        }*/
        
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
        
        XmlDocumentNode* recursiveXmlParser(std::string parentElementName, std::string totalStr) { // TODO
            
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
    }
    
    void readXmlFile(std::string filename) {
        
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
        
        
        XmlDocumentNode* rootNode = recursiveXmlParser("GameState", fileAsOneLinerString);
        std::cout << "Root node: " << rootNode->getNodeName() << std::endl;
        std::list<XmlDocumentNode*> children = rootNode->getChildNodes();
        std::cout << "name: " << children.front()->getNodeName() << std::endl;
        std::cout << "value: " << children.front()->getNodeValue() << std::endl;
        std::list<XmlDocumentNode*> grandchildren = children.front()->getChildNodes();
        std::cout << "name: " << grandchildren.front()->getNodeName() << std::endl;
        std::cout << "value: " << grandchildren.front()->getNodeValue() << std::endl;
        
        
        
        
        
        
        
        
        /* // SECOND PART!!!:
        XmlDocumentNode* amountOfPlayersNode = new XmlDocumentNode();
        amountOfPlayersNode->setNodeName("TODO_name");
        amountOfPlayersNode->setNodeValue("TODO_value");
        gameStateNode->addChildNode(amountOfPlayersNode);
        
        //std::cout << "thing1: " << gameStateNode.getChildNodes().pop_front().getNodeName();
        //std::cout << "thing2: " << gameStateNode.getChildNodes().pop_front().getNodeValue();
        */
    }
    void writeXmlFile(std::string filename) {
        // TODO
    }
}

