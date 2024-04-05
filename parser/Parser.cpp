#include "./Parser.hpp"
#include "../ast/Expressions/IExpression.hpp"
#include "../ast/Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../ast/Statements/LetStatment/LetStatement.hpp"
#include "../ast/Statements/ReturnStatement/ReturnStatement.hpp"
#include "Precedence.hpp"
#include "functional"
#include <iostream>
#include <vector>

Parser::Parser(Lexer lexer) : lexer(lexer) {
  this->nextToken();
  this->prefixParser[TokenType::IDENTIFIER] = [this]() -> IExpression * {
    return this->parseRvalueIdentifier();
  };
  this->prefixParser[TokenType::INT] = [this]() -> IExpression * {
    return this->parseIntegerLiteral();
  };
}

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
    return this->parseReturnStatement();
  }
  return this->parseStandAloneStatement(LOWEST);
}

LetStatement *Parser::parseLetStatement() {
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
  this->nextToken();
  return new LetStatement(lValueIdentifier, expression);
}

ReturnStatement *Parser::parseReturnStatement() {
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
  Token returnToken = this->currentToken;
  this->nextToken();
  return new ReturnStatement(
      new RValueIdentifier(returnToken, returnToken.literalValue));
}

StandAloneStatement *Parser::parseStandAloneStatement(Precedence precedence) {
  Token token = this->currentToken;
  auto prefixParser = this->prefixParser[token.tokenType];
  if (prefixParser == nullptr) {
    return nullptr;
  }
  IExpression *expression = prefixParser();
  return new StandAloneStatement(expression);
}

RValueIdentifier *Parser::parseRvalueIdentifier() {
  if (this->currentToken.tokenType != TokenType::IDENTIFIER) {
    return nullptr;
  }
  RValueIdentifier *rvalue =
      new RValueIdentifier(this->currentToken, this->currentToken.literalValue);
  this->nextToken();
  return rvalue;
}

IntegerLiteral *Parser::parseIntegerLiteral() {
  if (this->currentToken.tokenType != TokenType::INT) {
    return nullptr;
  }
  IntegerLiteral *integerLiteral =
      new IntegerLiteral(this->currentToken.literalValue);
  this->nextToken();
  return integerLiteral;
}
