
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
        
        
        // more testing
//         XmlDocumentNode* rootNode = recursiveXmlParser("GameState", fileAsOneLinerString);
//         std::cout << "Root node: " << rootNode->getNodeName() << std::endl;
//         std::list<XmlDocumentNode*> children = rootNode->getChildNodes();
//         std::cout << "name: " << children.front()->getNodeName() << std::endl;
//         std::cout << "value: " << children.front()->getNodeValue() << std::endl;
//         std::list<XmlDocumentNode*> grandchildren = children.front()->getChildNodes();
//         std::cout << "name: " << grandchildren.front()->getNodeName() << std::endl;
//         std::cout << "value: " << grandchildren.front()->getNodeValue() << std::endl;
        
        
        
        
        
        
        
        
        /* // SECOND PART!!!:
        XmlDocumentNode* amountOfPlayersNode = new XmlDocumentNode();
        amountOfPlayersNode->setNodeName("TODO_name");
        amountOfPlayersNode->setNodeValue("TODO_value");
        gameStateNode->addChildNode(amountOfPlayersNode);
        
        //std::cout << "thing1: " << gameStateNode.getChildNodes().pop_front().getNodeName();
        //std::cout << "thing2: " << gameStateNode.getChildNodes().pop_front().getNodeValue();
        */
        
        return GameState();
    }
    void writeXmlFile(std::string filename) {
        // TODO
    }
}

