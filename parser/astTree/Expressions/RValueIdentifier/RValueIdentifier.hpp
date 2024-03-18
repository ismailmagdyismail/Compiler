#ifndef __RVALUEIDENTIFIER_HPP
#define __RVALUEIDENTIFIER_HPP

#include "../../../../tokens/Token.hpp"
#include "../Expression.hpp"

class RValueIdentifier : public Expression {
public:
  RValueIdentifier(Token token);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual ~RValueIdentifier();

private:
  Token token;
};

#endif
