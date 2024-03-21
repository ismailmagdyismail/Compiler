#include "./ExpressionStatement.hpp"

ExpressionStatement::ExpressionStatement(Token token, IExpression *value) {
  this->token = token;
  this->value = value;
}

ExpressionStatement::ExpressionStatement(const ExpressionStatement &other) {
  this->value = other.value->clone();
  this->token = other.token;
}

ExpressionStatement &
ExpressionStatement::operator=(const ExpressionStatement &other) {
  this->token = other.token;
  this->value = other.value->clone();
  return *this;
}

std::string ExpressionStatement::getNodeType() {
  return "ExpressionStatement ExpressionNode";
}

std::string ExpressionStatement::getTokenLiteral() {
  return this->token.literalValue;
}

std::string ExpressionStatement::getValueLiteral() {
  return this->value->getValueLiteral();
}

ExpressionStatement::~ExpressionStatement() { delete this->value; }
