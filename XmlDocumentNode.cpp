
#include "XmlDocumentNode.hpp"

XmlDocumentNode::XmlDocumentNode(std::string rootElementName, std::string rootElementValue) {
        
    elementName = rootElementName;
    elementValue = rootElementValue;
}

std::string XmlDocumentNode::getNodeName() {
    return elementName;
}

std::string XmlDocumentNode::getNodeValue() {
    return elementValue;
}

void XmlDocumentNode::setNodeName(std::string nodeName) {
    this->elementName = nodeName;
}

void XmlDocumentNode::setNodeValue(std::string nodeValue) {
    this->elementValue = nodeValue;
}

std::list<XmlDocumentNode*> XmlDocumentNode::getChildNodes() {
    return childNodes;
}

void XmlDocumentNode::addChildNode(XmlDocumentNode* childNodeToAdd) {
    childNodes.push_back(childNodeToAdd);
}

void XmlDocumentNode::addChildNodes(std::list<XmlDocumentNode*> childNodesToAdd) {
    
    for(int i = 0; i < childNodesToAdd.size(); i++) {
        childNodes.push_back( childNodesToAdd.front() );
        childNodesToAdd.pop_front();
    }
}
