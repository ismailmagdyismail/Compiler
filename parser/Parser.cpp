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
    return this->createRvalueIdentifier();
  };
  this->prefixParser[TokenType::INT] = [this]() -> IExpression * {
    return this->createIntegerLiteral();
  };
  this->prefixParser[TokenType::BANG] = [this]() -> IExpression * {
    return this->parsePrefixOperator();
  };
  this->prefixParser[TokenType::MINUS] = [this]() -> IExpression * {
    return this->parsePrefixOperator();
  };
  // this->infixParser[TokenType::PLUS] = [this]() -> IExpression * {
  //   return this->parseBinaryExpression();
  // }
}

void Parser::nextToken() {
  this->currentToken = this->peekToken;
  this->peekToken = lexer.nextToken();
  // this->currentToken = lexer.nextToken();
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
  Token token = this->currentToken;
  auto prefixParser = this->prefixParser[token.tokenType];
  if (prefixParser == nullptr) {
    this->addError("No parsing function found for current token" +
                   this->currentToken.literalValue);
    return nullptr;
  }
  IExpression *leftExpression = prefixParser();
  return leftExpression;
}

RValueIdentifier *Parser::createRvalueIdentifier() {
  RValueIdentifier *rvalue =
      new RValueIdentifier(this->currentToken, this->currentToken.literalValue);
  return rvalue;
}

IntegerLiteral *Parser::createIntegerLiteral() {
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

BinaryExpression *Parser::parseBinaryExpression() {
  if (this->currentToken.tokenType != TokenType::INT &&
      this->currentToken.tokenType != TokenType::IDENTIFIER) {
    this->addError("Not a valid LeftValue ");
    return nullptr;
  }
  if (this->currentToken.tokenType != TokenType::PLUS) {
    this->addError(
        "Token " +
        TokenActions::getTokenLiteralValue(this->currentToken.tokenType) +
        "is not a Valid Binary Operator");
    return nullptr;
  }

  if (this->currentToken.tokenType != TokenType::INT &&
      this->currentToken.tokenType != TokenType::IDENTIFIER) {
    this->addError("Not a valid RightValue ");
    return nullptr;
  }
}
