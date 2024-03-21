#include "./RValueIdentifier.hpp"
#include <iostream>

RValueIdentifier::RValueIdentifier(const RValueIdentifier &other) {
  this->value = other.value;
  this->token = other.token;
}

RValueIdentifier::RValueIdentifier(Token token, std::string value) {
  this->token = token;
  this->value = value;
}

RValueIdentifier &RValueIdentifier::operator=(const RValueIdentifier &other) {
  this->token = other.token;
  this->value = other.value;
  return *this;
}

std::string RValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string RValueIdentifier::getNodeType() { return "IdentifierNode"; }

std::string RValueIdentifier::getValueLiteral() { return this->value; }

IExpression *RValueIdentifier::clone() {
  return new RValueIdentifier(this->token, this->value);
}

RValueIdentifier::~RValueIdentifier() {}
