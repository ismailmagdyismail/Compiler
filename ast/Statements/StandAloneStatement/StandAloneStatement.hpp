#ifndef __STANDALONESTATEMENT_HPP__
#define __STANDALONESTATEMENT_HPP__

#include "../../../tokens/Token.hpp"
#include "../../Expressions/IExpression.hpp"
#include "../IStatement.hpp"

class StandAloneStatement : public IStatement {
public:
  StandAloneStatement() = default;
  StandAloneStatement(Token token, IExpression *expression);
  StandAloneStatement(const StandAloneStatement &other);
  StandAloneStatement &operator=(const StandAloneStatement &other);

  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual std::string getExpressionValue();
  virtual std::string toString() override;
  virtual IStatement *clone() override;
  void setToken(Token token);
  void setExpression(IExpression *expression);
  virtual ~StandAloneStatement();

public:
  IExpression *expression;
  Token token;
};

#endif
