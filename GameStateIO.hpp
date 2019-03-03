

#ifndef GAMESTATEIO_HPP_
#define GAMESTATEIO_HPP_

#include <string>
//#include "XmlDocumentNode.hpp"

namespace GameStateIO {
    
    void readXmlFile(std::string filename);
    void writeXmlFile(std::string filename);
    //std::list<XmlDocumentNode*> recursive(std::string str, int endOp, int begClo);
}

#endif
