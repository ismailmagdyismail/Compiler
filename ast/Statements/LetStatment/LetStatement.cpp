#include "./LetStatement.hpp"

LetStatement::LetStatement(const LetStatement &other)
    : identifier(other.identifier) {
  this->token = TokenActions::createToken(TokenType::LET);
  this->value = other.value->clone();
}

LetStatement::LetStatement(LValueIdentifier identifier, IExpression *value)
    : identifier(identifier) {
  this->token = TokenActions::createToken(TokenType::LET);
  this->value = value->clone();
}

LetStatement &LetStatement::operator=(const LetStatement &other) {
  this->token = TokenActions::createToken(TokenType::LET);
  this->identifier = other.identifier;
  this->value = other.value->clone();
  return *this;
}

std::string LetStatement::getTokenLiteral() { return this->token.literalValue; }

std::string LetStatement::getNodeType() { return "Let Statement Node"; }

std::string LetStatement::getIdentifierLiteral() {
  return this->identifier.getTokenLiteral();
}

std::string LetStatement::getValueLiteral() {
  return this->value->getTokenLiteral();
}

IStatement *LetStatement::clone() {
  return new LetStatement(this->identifier, value->clone());
}

LetStatement::~LetStatement() { delete this->value; }
