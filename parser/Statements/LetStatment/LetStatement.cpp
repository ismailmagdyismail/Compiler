#include "./LetStatement.hpp"

LetStatement::LetStatement(Identifier identifier, Expression *value)
    : identifier(identifier) {
  this->value = value;
}

std::string LetStatement::getTokenLiteral() { return "Let statment"; }

std::string LetStatement::getIdentifierLiteral() {
  return this->identifier.getTokenLiteral();
}

LetStatement::~LetStatement() {
  // TODO
  delete this->value;
}
