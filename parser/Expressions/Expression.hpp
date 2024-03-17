#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

#include "../IAST.hpp"

class ExpressionNode : public ASTNode {
public:
  virtual std::string getTokenLiteral() override;
};

#endif
