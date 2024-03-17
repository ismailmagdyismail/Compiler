#ifndef __LETSTATEMENT_HPP__
#define __LETSTATEMENT_HPP__

#include "../../../tokens/Token.hpp"
#include "../../Expressions/Expression.hpp"
#include "../../Identifier/Identifier.hpp"
#include "../Statment.hpp"

/*
 - Compund Pattern
 - Act as a facade for its internal attributes to provide better encapsulation
*/

class LetStatement : public Statement {
public:
  LetStatement(Identifier identifier, Expression *value);
  virtual std::string getTokenLiteral() override;
  std::string getIdentifierLiteral();
  ~LetStatement();

private:
  Token token;
  Expression *value;
  Identifier identifier;
};

#endif
