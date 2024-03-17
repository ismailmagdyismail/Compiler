#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

#include "../IASTNode.hpp"

/*
 - Compund Pattern
 - Act as a facade for its internal attributes
*/

class Expression : public ASTNode {
public:
  virtual std::string getNodeType() override;
  virtual ~Expression();
};

#endif
