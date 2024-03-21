#include "./LValueIdentifier.hpp"
#include <iostream>

LValueIdentifier::LValueIdentifier(const LValueIdentifier &other) {
  this->token = other.token;
}

LValueIdentifier::LValueIdentifier(Token token) { this->token = token; }

LValueIdentifier &LValueIdentifier::operator=(const LValueIdentifier &other) {
  this->token = other.token;
  return *this;
}

std::string LValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string LValueIdentifier::getNodeType() { return "IdentifierNode"; }

std::string LValueIdentifier::toString() { return this->getTokenLiteral(); }

IStatement *LValueIdentifier::clone() {
  return new LValueIdentifier(this->token);
}

LValueIdentifier::~LValueIdentifier() {}
