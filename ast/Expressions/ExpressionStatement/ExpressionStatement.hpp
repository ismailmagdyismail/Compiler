#ifndef __EXPRESSIONSTATEMENT_HPP__
#define __EXPRESSIONSTATEMENT_HPP__

#include "../../../tokens/Token.hpp"
#include "../IExpression.hpp"

class ExpressionStatement : public IExpression {
public:
  ExpressionStatement(Token token, IExpression *value);
  ExpressionStatement(const ExpressionStatement &other);
  ExpressionStatement &operator=(const ExpressionStatement &other);

  virtual std::string getNodeType() override;
  virtual std::string getTokenLiteral() override;
  virtual std::string getValueLiteral() override;
  virtual IExpression *clone() override;

  virtual ~ExpressionStatement();

private:
  Token token;
  IExpression *value;
};

#endif
