#include "./LValueIdentifier.hpp"
#include <iostream>

LValueIdentifier::LValueIdentifier(Token token) { this->token = token; }

std::string LValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string LValueIdentifier::getNodeType() { return "IdentifierNode"; }

LValueIdentifier::~LValueIdentifier() {
  std::cout << "Deleting LValue IdentifierNode\n"; // Debugging
}
