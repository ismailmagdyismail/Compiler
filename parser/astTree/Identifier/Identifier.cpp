#include "./Identifier.hpp"
#include <iostream>

Identifier::Identifier(Token token) { this->token = token; }

std::string Identifier::getTokenLiteral() { return this->token.literalValue; }

std::string Identifier::getNodeType() { return "IdentifierNode"; }

Identifier::~Identifier() {
  std::cout << "Deleting IdentifierNode\n"; // Debugging
}
