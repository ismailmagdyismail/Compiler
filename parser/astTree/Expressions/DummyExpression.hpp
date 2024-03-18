#ifndef __DUMMYEXPRESSION_HPP__
#define __DUMMYEXPRESSION_HPP__
#include "./Expression.hpp"

class DummyExpression : public Expression {
public:
  DummyExpression();
  virtual std::string getTokenLiteral() override;
  virtual ~DummyExpression();
};

#endif
