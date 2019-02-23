
#ifndef XMLDOCUMENTNODE_HPP_
#define XMLDOCUMENTNODE_HPP_

#include <string>
#include <list>

class XmlDocumentNode {
    private:
        std::list<XmlDocumentNode> childNodes;
        std::string nodeValue;
    public:
        std::string getNodeValue();
        void setNodeValue(std::string nodeValue);
        std::list<XmlDocumentNode> getChildNodes();
        void addChildNode(XmlDocumentNode childNodeToAdd);
        void addChildNodes(std::list<XmlDocumentNode> childNodesToAdd);
};

#endif
