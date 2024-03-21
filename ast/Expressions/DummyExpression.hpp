#ifndef __DUMMYEXPRESSION_HPP__
#define __DUMMYEXPRESSION_HPP__
#include "./IExpression.hpp"

class DummyExpression : public IExpression {
public:
  DummyExpression();
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual std::string getValueLiteral() override;
  virtual IExpression *clone() override;
  virtual ~DummyExpression();
};

#endif
