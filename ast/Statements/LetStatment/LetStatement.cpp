#include "./LetStatement.hpp"
#include <iostream>

LetStatement::LetStatement(LValueIdentifier identifier, IExpression *value)
    : identifier(identifier) {
  this->token = TokenActions::createToken(TokenType::LET);
  this->value = value;
}

std::string LetStatement::getTokenLiteral() { return "Let statment"; }

std::string LetStatement::getIdentifierLiteral() {
  return this->identifier.getTokenLiteral();
}

LetStatement::~LetStatement() {
  std::cout << "Deleting Let statment\n";
  delete this->value;
}
