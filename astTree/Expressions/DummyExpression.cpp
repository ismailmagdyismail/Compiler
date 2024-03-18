#include "./DummyExpression.hpp"
#include <iostream>

DummyExpression::DummyExpression() {}

std::string DummyExpression::getTokenLiteral() {
  return "Dummy Expression Node";
}
std::string DummyExpression::getNodeType() { return "Expression dymmy node"; }

DummyExpression::~DummyExpression() {
  std::cout << "Dummy Expression Node Destructor\n"; // denugging
}
