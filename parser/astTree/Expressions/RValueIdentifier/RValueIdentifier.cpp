#include "./RValueIdentifier.hpp"
#include <iostream>

RValueIdentifier::RValueIdentifier(Token token) { this->token = token; }

std::string RValueIdentifier::getTokenLiteral() {
  return this->token.literalValue;
}

std::string RValueIdentifier::getNodeType() { return "IdentifierNode"; }

RValueIdentifier::~RValueIdentifier() {
  std::cout << "Deleting RValue IdentifierNode\n"; // Debugging
}
