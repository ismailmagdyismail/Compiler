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
  LetStatement(const LetStatement &other);
  LetStatement(LValueIdentifier identifier, IExpression *value);
  LetStatement &operator=(const LetStatement &other);

  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual IStatement *clone() override;
  std::string getAssignedValue();
  std::string getIdentifierLiteral();

  ~LetStatement();

private:
  Token token;
  IExpression *value;
  LValueIdentifier identifier;
};

#endif
