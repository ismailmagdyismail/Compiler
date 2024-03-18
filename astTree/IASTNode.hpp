#ifndef __IAST_HPP__
#define __IAST_HPP__
#include <string>

class ASTNode {
public:
  virtual std::string getTokenLiteral() = 0; // for debugging
  virtual std::string getNodeType() = 0;     // for debugging
  virtual ~ASTNode();
};

#endif
