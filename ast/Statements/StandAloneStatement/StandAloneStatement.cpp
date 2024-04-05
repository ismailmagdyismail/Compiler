#include "./StandAloneStatement.hpp"

StandAloneStatement::StandAloneStatement(ExpressionStatement expression)
    : expressionStatement(expression) {}

StandAloneStatement::StandAloneStatement(const StandAloneStatement &other)
    : expressionStatement(other.expressionStatement) {}

StandAloneStatement &
StandAloneStatement::operator=(const StandAloneStatement &other) {
  this->expressionStatement = other.expressionStatement;
  return *this;
}

std::string StandAloneStatement::getNodeType() {
  return this->expressionStatement.getNodeType();
}

std::string StandAloneStatement::getTokenLiteral() {
  return this->expressionStatement.getTokenLiteral();
}

std::string StandAloneStatement::getExpressionValue() {
  return this->expressionStatement.getValueLiteral();
}

std::string StandAloneStatement::toString() {
  return this->expressionStatement.toString();
}

IStatement *StandAloneStatement::clone() {
  return new StandAloneStatement(this->expressionStatement);
}
