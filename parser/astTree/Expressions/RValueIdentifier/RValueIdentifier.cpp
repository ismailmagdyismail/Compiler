#include "./RValueIdentifier.hpp"
#include <iostream>

RValueIdentifier::RValueIdentifier(Token token, std::string value) {
  this->token = token;
  this->value = value;
}

std::string RValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string RValueIdentifier::getNodeType() { return "IdentifierNode"; }

RValueIdentifier::~RValueIdentifier() {
  std::cout << "Deleting RValue IdentifierNode\n"; // Debugging
}
