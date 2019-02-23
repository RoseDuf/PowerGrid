
#ifndef XMLDOCUMENTTREE_HPP_
#define XMLDOCUMENTTREE_HPP_

#include "XmlDocumentNode.hpp"

class XmlDocumentTree {
    private:
        XmlDocumentNode rootNode;
    public:
        XmlDocumentNode getRootNode();
        void readXmlFile(std::string filename);
        void writeXmlFile(std::string filename);
};

#endif
