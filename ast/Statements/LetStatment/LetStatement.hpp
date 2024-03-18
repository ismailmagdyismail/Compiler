#ifndef __LETSTATEMENT_HPP__
#define __LETSTATEMENT_HPP__

#include "../../../tokens/Token.hpp"
#include "../../Expressions/IExpression.hpp"
#include "../IStatement.hpp"
#include "../LValueIdentifier/LValueIdentifier.hpp"
/*
 - Compund Pattern
 - Act as a facade for its internal attributes to provide better encapsulation
*/

class LetStatement : public IStatement {
public:
  LetStatement(LValueIdentifier identifier, IExpression *value);
  virtual std::string getTokenLiteral() override;
  std::string getIdentifierLiteral();
  ~LetStatement();

private:
  Token token;
  IExpression *value;
  LValueIdentifier identifier;
};

#endif
