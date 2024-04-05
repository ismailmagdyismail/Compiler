#ifndef __INTEGERLITERAL_HPP__
#define __INTEGERLITERAL_HPP__

#include "../../../tokens/Token.hpp"
#include "../IExpression.hpp"

class IntegerLiteral : public IExpression {
public:
  IntegerLiteral(long long value);

  virtual IExpression *clone() override;
  virtual std::string toString() override;
  virtual std::string getNodeType() override;
  virtual std::string getTokenLiteral() override;
  virtual std::string getValueLiteral() override;
  virtual long long getIntegerValue();

private:
  Token token;
  long long value;
};

#endif
