#ifndef __PREFIXEXPRESSION_HPP__
#define __PREFIXEXPRESSION_HPP__

#include "../../../tokens/Token.hpp"
#include "../IExpression.hpp"

class PrefixExpression : public IExpression {
public:
  PrefixExpression(Token prefixOperator, IExpression *rightExpression);
  PrefixExpression(const PrefixExpression &other);

  virtual IExpression *clone() override;
  virtual std::string toString() override;
  virtual std::string getNodeType() override;
  virtual std::string getTokenLiteral() override;
  virtual std::string getValueLiteral() override;

  virtual ~PrefixExpression();

private:
  Token prefixOperator;
  IExpression *rightExpression;
};
#endif
