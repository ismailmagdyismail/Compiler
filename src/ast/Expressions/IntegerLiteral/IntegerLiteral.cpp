#include "./IntegerLiteral.hpp"
#include "../../../ObjectSystem/IntegerValue/IntegerValue.hpp"
#include <string>

IntegerLiteral::IntegerLiteral(long long value) {
  this->token = TokenActions::createToken(std::to_string(value));
  this->value = value;
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

IObject* IntegerLiteral::objectValue(){
    return new IntegerValue(value);
}

std::string IntegerLiteral::toString() { return this->getValueLiteral(); }
