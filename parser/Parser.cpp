#include "./Parser.hpp"
#include "../ast/Expressions/IExpression.hpp"
#include "../ast/Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../ast/Statements/LetStatment/LetStatement.hpp"
#include "../ast/Statements/ReturnStatement/ReturnStatement.hpp"
#include "Precedence/Precedence.hpp"
#include "functional"
#include <iostream>
#include <string>
#include <vector>

Parser::Parser(Lexer lexer) : lexer(lexer) {
  this->nextToken();
  this->nextToken();
  this->prefixParser[TokenType::IDENTIFIER] = [this]() -> IExpression * {
    return this->parseRValueIdentifier();
  };
  this->prefixParser[TokenType::INT] = [this]() -> IExpression * {
    return this->parseIntegerLiteral();
  };
  this->prefixParser[TokenType::BANG] = [this]() -> IExpression * {
    return this->parsePrefixOperator();
  };
  this->prefixParser[TokenType::MINUS] = [this]() -> IExpression * {
    return this->parsePrefixOperator();
  };
  this->infixParsers[TokenType::PLUS] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::MINUS] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::SLASH] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::ASTERISK] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::EQUAL] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::NOT_EQUAL] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::GT] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
  this->infixParsers[TokenType::LT] =
      [this](IExpression *leftExpression) -> IExpression * {
    return this->parseBinaryExpression(leftExpression);
  };
}

void Parser::nextToken() {
  this->currentToken = this->peekToken;
  this->peekToken = lexer.nextToken();
}

Precedence Parser::currentPrecedence() {
  return TokensPrecedence::getTokenPrecedence(this->currentToken.tokenType);
}

Precedence Parser::peekPrecedence() {
  return TokensPrecedence::getTokenPrecedence(this->peekToken.tokenType);
}

void Parser::addError(std::string errorMessage) {
  this->errors.push_back(errorMessage);
}

std::vector<std::string> Parser::getErrors() { return this->errors; }

AST Parser::parseProgram() {
  AST ast;
  while (this->currentToken.tokenType != TokenType::END_OF_FILE) {
    if (this->currentToken.tokenType == TokenType::SEMI_COLON) {
      this->nextToken();
      continue;
    }
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
  return this->parseStandAloneStatement();
}

LetStatement *Parser::parseLetStatement() {
  // TODO add parsing expression later , when
  if (this->peekToken.tokenType != TokenType::IDENTIFIER) {
    this->addError("Invalid Identifier");
    return nullptr;
  }
  this->nextToken();
  Token identifierToken = this->currentToken;

  if (this->peekToken.tokenType != TokenType::ASSIGN) {
    this->addError("Missing " +
                   TokenActions::getTokenLiteralValue(TokenType::ASSIGN) +
                   " (assignment) Sign");
    return nullptr;
  }
  this->nextToken();

  if (this->peekToken.tokenType != TokenType::INT &&
      this->peekToken.tokenType != TokenType::IDENTIFIER) {
    // TODO parse RValue expression
    this->addError("Invalid RValue");
    return nullptr;
  }
  this->nextToken();
  Token rValueToken = this->currentToken;
  LValueIdentifier lValueIdentifier = LValueIdentifier(identifierToken);
  IExpression *expression =
      new RValueIdentifier(rValueToken, rValueToken.literalValue);
  return new LetStatement(lValueIdentifier, expression);
}

ReturnStatement *Parser::parseReturnStatement() {
  // TODO parse Return expression
  if (this->peekToken.tokenType != TokenType::IDENTIFIER &&
      this->peekToken.tokenType != TokenType::INT) {
    this->addError("Invalid return value ");
    return nullptr;
  }
  this->nextToken();
  Token returnToken = this->currentToken;
  return new ReturnStatement(
      new RValueIdentifier(returnToken, returnToken.literalValue));
}

StandAloneStatement *Parser::parseStandAloneStatement() {
  StandAloneStatement *standAloneStatement = new StandAloneStatement();
  standAloneStatement->setToken(this->currentToken);

  IExpression *expression = this->parseExpression(LOWEST);
  standAloneStatement->setExpression(expression);

  return standAloneStatement;
}

IExpression *Parser::parseExpression(Precedence precedence) {
  auto prefixParser = this->prefixParser[this->currentToken.tokenType];
  if (prefixParser == nullptr) {
    this->addError("No parsing function found for current token" +
                   this->currentToken.literalValue);
    return nullptr;
  }
  IExpression *expression = prefixParser();
  while (this->peekToken.tokenType != TokenType::SEMI_COLON &&
         precedence < this->peekPrecedence()) {
    auto infixParser = this->infixParsers[this->peekToken.tokenType];
    this->nextToken();
    expression = infixParser(expression);
  }
  return expression;
}

RValueIdentifier *Parser::parseRValueIdentifier() {
  RValueIdentifier *rvalue =
      new RValueIdentifier(this->currentToken, this->currentToken.literalValue);
  return rvalue;
}

IntegerLiteral *Parser::parseIntegerLiteral() {
  IntegerLiteral *integerLiteral =
      new IntegerLiteral(std::stol(this->currentToken.literalValue));
  return integerLiteral;
}

PrefixExpression *Parser::parsePrefixOperator() {
  PrefixExpression *prefixExpression = new PrefixExpression();
  prefixExpression->setPrefixOperator(this->currentToken);
  this->nextToken();
  IExpression *rightExpression = this->parseExpression(PREFIX);
  prefixExpression->setRightExpression(rightExpression);
  return prefixExpression;
}

BinaryExpression *Parser::parseBinaryExpression(IExpression *leftExpression) {
  BinaryExpression *binaryExpression = new BinaryExpression();
  binaryExpression->setLeftExpression(leftExpression);
  binaryExpression->setBinaryOperator(this->currentToken);
  Precedence precedence = this->currentPrecedence();
  this->nextToken();
  IExpression *rightExpression = this->parseExpression(precedence);
  binaryExpression->setRightExpression(rightExpression);
  return binaryExpression;
}
