#include "./BinaryExpression.hpp"

BinaryExpression::BinaryExpression(IExpression *leftExpression,
                                   IExpression *rightExpression,
                                   Token binaryOperator) {
  this->leftExpression = leftExpression;
  this->rightExpression = rightExpression;
  this->binaryOperator = binaryOperator;
}

BinaryExpression::BinaryExpression(const BinaryExpression &other) {
  this->leftExpression = other.leftExpression->clone();
  this->rightExpression = other.rightExpression->clone();
  this->binaryOperator = other.binaryOperator;
}

std::string BinaryExpression::getNodeType() { return "BinaryExpression Node"; }

std::string BinaryExpression::getTokenLiteral() {
  return this->binaryOperator.literalValue;
}

std::string BinaryExpression::getValueLiteral() {
  return this->binaryOperator.literalValue;
}

std::string BinaryExpression::toString() {
  return this->leftExpression->toString() + this->binaryOperator.literalValue +
         this->rightExpression->toString();
}

IExpression *BinaryExpression::clone() { return new BinaryExpression(*this); }

BinaryExpression::~BinaryExpression() {
  delete this->leftExpression;
  delete this->rightExpression;
}
