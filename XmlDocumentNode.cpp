

#include "XmlDocumentNode.hpp"

std::string XmlDocumentNode::getNodeValue() {
    return getNodeValue();
}

std::list<XmlDocumentNode> XmlDocumentNode::getChildNodes() {
    return childNodes;
}

void XmlDocumentNode::addChildNode(XmlDocumentNode childNodeToAdd) {
    childNodes.push_back(childNodeToAdd);
}

void XmlDocumentNode::addChildNodes(std::list<XmlDocumentNode> childNodesToAdd) {
    
    for(int i = 0; i < childNodesToAdd.size(); i++) {
        childNodesToAdd.push_back( childNodes.front() );
        childNodes.pop_front();
    }
}
