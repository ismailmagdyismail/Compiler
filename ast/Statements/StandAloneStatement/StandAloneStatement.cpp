#include "./StandAloneStatement.hpp"

StandAloneStatement::StandAloneStatement(Token token, IExpression *expression) {
  this->token = token;
  this->expression = expression;
}

StandAloneStatement::StandAloneStatement(const StandAloneStatement &other) {
  this->token = other.token;
  this->expression = other.expression->clone();
}

StandAloneStatement &
StandAloneStatement::operator=(const StandAloneStatement &other) {
  this->expression = other.expression->clone();
  this->token = other.token;
  return *this;
}

void StandAloneStatement::setExpression(IExpression *expression) {
  this->expression = expression;
}

void StandAloneStatement::setToken(Token token) { this->token = token; }

std::string StandAloneStatement::getNodeType() {
  return this->expression->getNodeType();
}

std::string StandAloneStatement::getTokenLiteral() {
  return this->expression->getTokenLiteral();
}

std::string StandAloneStatement::getExpressionValue() {
  return this->expression->getValueLiteral();
}

std::string StandAloneStatement::toString() {
  return this->expression->toString();
}

IStatement *StandAloneStatement::clone() {
  return new StandAloneStatement(*this);
}

StandAloneStatement::~StandAloneStatement() { delete this->expression; }
