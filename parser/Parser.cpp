#include "./Parser.hpp"
#include "../ast/Expressions/IExpression.hpp"
#include "../ast/Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../ast/Statements/LetStatment/LetStatement.hpp"
#include "../ast/Statements/ReturnStatement/ReturnStatement.hpp"
#include "./exceptions/ParserError.hpp"
#include <vector>

Parser::Parser(Lexer lexer) : lexer(lexer) { this->nextToken(); }

void Parser::nextToken() { currentToken = lexer.nextToken(); }

void Parser::addError(std::string errorMessage) {
  this->errors.push_back(errorMessage);
}

std::vector<std::string> Parser::getErrors() { return this->errors; }

AST Parser::parseProgram() {
  AST ast;
  while (this->currentToken.tokenType != TokenType::END_OF_FILE) {
    IStatement *statement = this->parseStatement();
    if (statement != nullptr) {
      ast.addStatement(statement);
    }
    this->nextToken();
  }
  return ast;
}

IStatement *Parser::parseStatement() {
  if (this->currentToken.tokenType == TokenType::LET) {
    return this->parseLetStatement();
  }
  if (this->currentToken.tokenType == TokenType::RETURN) {
    return this->parseReturnExpression();
  }
  return nullptr;
}

IStatement *Parser::parseLetStatement() {
  // TODO add parsing expression later , when
  // expression parser is add
  if (this->currentToken.tokenType != TokenType::LET) {
    this->addError("Invalid Let statement");
    return nullptr;
  }

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::IDENTIFIER) {
    this->addError("Invalid Identifier");
    return nullptr;
  }
  Token identifierToken = this->currentToken;

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::ASSIGN) {
    this->addError("Missing " +
                   TokenActions::getTokenLiteralValue(TokenType::ASSIGN) +
                   " (assignment) Sign");

    return nullptr;
  }

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::INT &&
      this->currentToken.tokenType != TokenType::IDENTIFIER) {
    this->addError("Invalid RValue");
    return nullptr;
  }
  Token rValueToken = this->currentToken;
  LValueIdentifier lValueIdentifier = LValueIdentifier(identifierToken);
  IExpression *expression =
      new RValueIdentifier(rValueToken, rValueToken.literalValue);
  return new LetStatement(lValueIdentifier, expression);
}

IStatement *Parser::parseReturnExpression() {
  if (this->currentToken.tokenType != TokenType::RETURN) {
    this->addError("Invalid return statement");
    return nullptr;
  }
  this->nextToken();
  if (this->currentToken.tokenType != TokenType::IDENTIFIER &&
      this->currentToken.tokenType != TokenType::INT) {
    this->addError("Invalid return value ");
    return nullptr;
  }
  return new ReturnStatement(new RValueIdentifier(
      this->currentToken, this->currentToken.literalValue));
}
