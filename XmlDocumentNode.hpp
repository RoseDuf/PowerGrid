
#ifndef XMLDOCUMENTNODE_HPP_
#define XMLDOCUMENTNODE_HPP_

#include <string>
#include <list>

class XmlDocumentNode {
    private:
        std::list<XmlDocumentNode*> childNodes;
        std::string elementName;
        std::string elementValue;
    public:
        XmlDocumentNode(std::string elementName, std::string elementValue);
        std::string getNodeName();
        std::string getNodeValue();
        void setNodeName(std::string nodeName);
        void setNodeValue(std::string nodeValue);
        std::list<XmlDocumentNode*> getChildNodes();
        void addChildNode(XmlDocumentNode* childNodeToAdd);
        void addChildNodes(std::list<XmlDocumentNode*> childNodesToAdd);
        ~XmlDocumentNode();
};

#endif
