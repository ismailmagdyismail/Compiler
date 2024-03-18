#ifndef __LVALUEIDENTIFIER_HPP
#define __LVALUEIDENTIFIER_HPP

#include "../../../tokens/Token.hpp"
#include "../Statment.hpp"

class LValueIdentifier : public Statement {
public:
  LValueIdentifier(Token token);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual ~LValueIdentifier();

private:
  Token token;
};

#endif
