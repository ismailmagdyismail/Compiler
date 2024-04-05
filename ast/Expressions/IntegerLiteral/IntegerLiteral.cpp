#include "./IntegerLiteral.hpp"
#include <string>

IntegerLiteral::IntegerLiteral(long long value) {
  this->token = TokenActions::createToken(std::to_string(value));
  this->value = value;
}

IntegerLiteral::IntegerLiteral(std::string value) {
  this->token = TokenActions::createToken(value);
  this->value = std::stol(value);
}

IExpression *IntegerLiteral::clone() { return new IntegerLiteral(this->value); }

long long IntegerLiteral::getIntegerValue() { return this->value; }

std::string IntegerLiteral::getNodeType() {
  return "IntegerLiteral Expression Node";
}

std::string IntegerLiteral::getTokenLiteral() {
  return this->token.literalValue;
}

std::string IntegerLiteral::getValueLiteral() {
  return std::to_string(this->value);
}

std::string IntegerLiteral::toString() { return this->getValueLiteral(); }
