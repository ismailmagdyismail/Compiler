#ifndef __BINARYEXPRESSION_HPP__
#define __BINARYEXPRESSION_HPP__

#include "../../../tokens/Token.hpp"
#include "../IExpression.hpp"
#include <string>

class BinaryExpression : public IExpression {
public:
  BinaryExpression();
  BinaryExpression(IExpression *leftExpression, IExpression *righExpression,
                   Token binaryOperator);
  BinaryExpression(const BinaryExpression &other);
  BinaryExpression &operator=(const BinaryExpression &other);
  virtual std::string toString() override;
  virtual std::string getNodeType() override;
  virtual std::string getTokenLiteral() override;
  virtual std::string getValueLiteral() override;
  virtual IObject* objectValue() override;
  void setLeftExpression(IExpression *leftExpression);
  void setRightExpression(IExpression *rightExpression);
  void setBinaryOperator(Token token);
  virtual IExpression *clone() override;
  virtual ~BinaryExpression();

private:
  IExpression *leftExpression;
  IExpression *rightExpression;
  Token binaryOperator;
};
#endif
