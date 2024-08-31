#include "./LetStatement.hpp"
#include "../../../ObjectSystem/NilValue/NilValue.hpp"


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

std::string LetStatement::getAssignedValue() {
  return this->value->getValueLiteral();
}

std::string LetStatement::toString() {
  return TokenActions::getTokenLiteralValue(TokenType::LET) + " " +
         this->identifier.toString() + " " +
         TokenActions::getTokenLiteralValue(TokenType::ASSIGN) + " " +
         this->value->toString();
}

IObject* LetStatement::objectValue(){
    return new NilValue();
}

IStatement *LetStatement::clone() {
  return new LetStatement(this->identifier, value->clone());
}

LetStatement::~LetStatement() { delete this->value; }
