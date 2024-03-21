#include "./DummyExpression.hpp"
#include <iostream>

DummyExpression::DummyExpression() {}

std::string DummyExpression::getTokenLiteral() {
  return "Dummy Expression Node";
}

std::string DummyExpression::getNodeType() { return "Expression dymmy node"; }

std::string DummyExpression::getValueLiteral() { return "Dummy value"; }

IExpression *DummyExpression::clone() { return new DummyExpression(); }

DummyExpression::~DummyExpression() {}
