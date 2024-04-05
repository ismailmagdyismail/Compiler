#ifndef __STANDALONESTATEMENT_HPP__
#define __STANDALONESTATEMENT_HPP__

#include "../../Expressions/ExpressionStatement/ExpressionStatement.hpp"
#include "../IStatement.hpp"

class StandAloneStatement : public IStatement {
public:
  StandAloneStatement(IExpression *expression);
  StandAloneStatement(const StandAloneStatement &other);
  StandAloneStatement &operator=(const StandAloneStatement &other);

  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual std::string getExpressionValue();
  virtual std::string toString() override;
  virtual IStatement *clone() override;

private:
  IExpression *expressionStatement;
};

#endif
