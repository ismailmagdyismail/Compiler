#include "./DummyExpression.hpp"
#include "Expression.hpp"
#include <iostream>

DummyExpression::DummyExpression() {}

std::string DummyExpression::getTokenLiteral() {
  return "Dummy Expression Node";
}

DummyExpression::~DummyExpression() {
  std::cout << "Dummy Expression Node Destructor\n"; // denugging
}
