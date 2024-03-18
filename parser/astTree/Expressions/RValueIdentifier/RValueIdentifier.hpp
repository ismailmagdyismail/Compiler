#ifndef __RVALUEIDENTIFIER_HPP
#define __RVALUEIDENTIFIER_HPP

#include "../../../../tokens/Token.hpp"
#include "../Expression.hpp"
#include <string>

class RValueIdentifier : public Expression {
public:
  RValueIdentifier(Token token, std::string value);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual ~RValueIdentifier();

private:
  Token token;
  std::string value;
};

#endif
