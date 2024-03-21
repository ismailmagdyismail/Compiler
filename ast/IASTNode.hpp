#ifndef __IAST_HPP__
#define __IAST_HPP__
#include <string>

class IASTNode {
public:
  virtual std::string getTokenLiteral() = 0; // for debugging
  virtual std::string getNodeType() = 0;     // for debugging
  virtual std::string toString() = 0;
  virtual ~IASTNode();
};

#endif
