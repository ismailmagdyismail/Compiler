#ifndef __RETURNSTATEMENT_HPP__
#define __RETURNSTATEMENT_HPP__

#include "../../../tokens/Token.hpp"
#include "../../Expressions/IExpression.hpp"
#include "../IStatement.hpp"

class ReturnStatement : public IStatement {
public:
  ReturnStatement(IExpression *value);
  ReturnStatement(const ReturnStatement &other);
  ReturnStatement &operator=(const ReturnStatement &other);

  virtual IStatement *clone() override;
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual std::string toString() override;
  virtual IObject* objectValue()override;
  ReturnStatement* getCopy();

  std::string getReturnedValue();
  std::string getValueLiteral();

  ~ReturnStatement();

private:
  Token token;
  IExpression *value;
};

#endif
