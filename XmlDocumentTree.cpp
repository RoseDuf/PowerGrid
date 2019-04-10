
#include "XmlDocumentTree.hpp"

XmlDocumentTree::XmlDocumentTree(XmlDocumentNode* rootNode) : rootNode(rootNode) {}

XmlDocumentTree::XmlDocumentTree(std::string rootElementName, std::string rootElementValue) {
    rootNode = new XmlDocumentNode(rootElementName, rootElementValue);
}

XmlDocumentNode* XmlDocumentTree::getRootNode() {
    return rootNode;
}

XmlDocumentTree::~XmlDocumentTree() {
    delete rootNode;
}
