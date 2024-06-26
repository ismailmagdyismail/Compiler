#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

#include "../IASTNode.hpp"

/*
 - Compund Pattern
 - Act as a facade for its internal attributes to provide better encapsulation
*/

class IExpression : public IASTNode {
public:
  virtual IExpression *clone() = 0;
  virtual std::string getValueLiteral() = 0;
  virtual ~IExpression();
};

#endif
