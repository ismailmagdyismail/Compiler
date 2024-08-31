#include "./BinaryExpression.hpp"
#include "../../../ObjectSystem/NilValue/NilValue.hpp"

#include <iostream>

BinaryExpression::BinaryExpression() {
  this->leftExpression = nullptr;
  this->rightExpression = nullptr;
}

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

BinaryExpression &BinaryExpression::operator=(const BinaryExpression &other) {
  this->leftExpression = other.leftExpression->clone();
  this->rightExpression = other.rightExpression->clone();
  this->binaryOperator = other.binaryOperator;
  return *this;
}

std::string BinaryExpression::getNodeType() { return "BinaryExpression Node"; }

std::string BinaryExpression::getTokenLiteral() {
  return this->binaryOperator.literalValue;
}

std::string BinaryExpression::getValueLiteral() {
  return this->binaryOperator.literalValue;
}

std::string BinaryExpression::toString() {
  return "("+this->leftExpression->toString() + this->binaryOperator.literalValue +
         this->rightExpression->toString()+")";
}

void BinaryExpression::setBinaryOperator(Token token) {
  this->binaryOperator = token;
}

void BinaryExpression::setLeftExpression(IExpression *leftExpression) {
  this->leftExpression = leftExpression;
}

void BinaryExpression::setRightExpression(IExpression *rightExpression) {
  this->rightExpression = rightExpression;
}

IObject* BinaryExpression::objectValue(){
    return new NilValue();
}

IExpression *BinaryExpression::clone() { return new BinaryExpression(*this); }

BinaryExpression::~BinaryExpression() {
  delete this->leftExpression;
  delete this->rightExpression;
}
