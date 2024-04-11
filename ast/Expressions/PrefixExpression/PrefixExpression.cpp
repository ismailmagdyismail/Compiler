#include "./PrefixExpression.hpp"

PrefixExpression::PrefixExpression(Token prefixOperator,
                                   IExpression *rightExpression) {
  this->prefixOperator = prefixOperator;
  this->rightExpression = rightExpression;
}

PrefixExpression::PrefixExpression(const PrefixExpression &other) {
  this->prefixOperator = other.prefixOperator;
  this->rightExpression = other.rightExpression->clone();
}

void PrefixExpression::setPrefixOperator(Token prefixOperator) {
  this->prefixOperator = prefixOperator;
}

void PrefixExpression::setRightExpression(IExpression *rightExpression) {
  this->rightExpression = rightExpression;
}

std::string PrefixExpression::toString() {
  return this->prefixOperator.literalValue + this->rightExpression->toString();
}

std::string PrefixExpression::getNodeType() { return "PrefixExpressionNode"; }

std::string PrefixExpression::getTokenLiteral() {
  return this->prefixOperator.literalValue;
}

std::string PrefixExpression::getValueLiteral() {
  return this->rightExpression->getValueLiteral();
}

IExpression *PrefixExpression::clone() { return new PrefixExpression(*this); }

PrefixExpression::~PrefixExpression() { delete this->rightExpression; }
