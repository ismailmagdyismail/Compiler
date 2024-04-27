#include "./ReturnStatement.hpp"

ReturnStatement::ReturnStatement(IExpression *value) {
  this->token = TokenActions::createToken(TokenType::RETURN);
  this->value = value;
}

ReturnStatement::ReturnStatement(const ReturnStatement &other) {
  this->token = other.token;
  this->value = other.value->clone();
}

ReturnStatement &ReturnStatement::operator=(const ReturnStatement &other) {
  this->token = other.token;
  this->value = other.value->clone();
  return *this;
}

std::string ReturnStatement::getNodeType() { return "Return StatementNode "; }

std::string ReturnStatement::getTokenLiteral() {
  return TokenActions::getTokenLiteralValue(TokenType::RETURN);
}

std::string ReturnStatement::getReturnedValue() {
  return this->value->getValueLiteral();
}

std::string ReturnStatement::toString() {
  return TokenActions::getTokenLiteralValue(TokenType::RETURN) + " " +
         this->value->toString();
}

ReturnStatement* ReturnStatement::getCopy() {
  return new ReturnStatement(*this);
}

IStatement *ReturnStatement::clone() {
  return new ReturnStatement(this->value->clone());
}

ReturnStatement::~ReturnStatement() { delete this->value; }
