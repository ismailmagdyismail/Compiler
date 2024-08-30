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
  this->prefixParser[TokenType::TRUE] = [this]() -> IExpression * {
    return this->parseBoolean();
  };
  this->prefixParser[TokenType::FALSE] = [this]() -> IExpression * {
    return this->parseBoolean();
  };
  this->prefixParser[TokenType::MINUS] = [this]() -> IExpression * {
    return this->parsePrefixOperator();
  };
  this->prefixParser[TokenType::LEFT_PARENTHESES] = [this]() -> IExpression * {
    return this->parseGroupedExpression();
  };
  this->prefixParser[TokenType::IF] = [this]() -> IExpression * {
    return this->parseIfExpression();
  };
  this->prefixParser[TokenType::FUNCTION] = [this]() -> IExpression * {
    return this->parseFunctionLiteral();
  };
  this->infixParsers[TokenType::LEFT_PARENTHESES] =[this](IExpression *leftExpression) -> IExpression * {
    return this->parseFunctionCallExpression(leftExpression);
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
  this->nextToken();
  LValueIdentifier lValueIdentifier = LValueIdentifier(identifierToken);
  IExpression* rhs = this->parseExpression(Precedence::LOWEST);
  if(this->currentToken.tokenType == TokenType::SEMI_COLON){
      this->nextToken();
  }
  return new LetStatement(lValueIdentifier, rhs);
}

ReturnStatement *Parser::parseReturnStatement() {
  this->nextToken();
  IExpression* returnValue = this->parseExpression(Precedence::LOWEST);
  if(this->currentToken.tokenType == TokenType::SEMI_COLON){
      this->nextToken();
  }
  return new ReturnStatement(returnValue);
}

StandAloneStatement *Parser::parseStandAloneStatement() {
  StandAloneStatement *standAloneStatement = new StandAloneStatement();
  standAloneStatement->setToken(this->currentToken);

  //TODO may retur NULL so check for it
  IExpression *expression = this->parseExpression(Precedence::LOWEST);
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
    IExpression* infixExpression = infixParser(expression);
    if(infixExpression != nullptr){
        expression = infixExpression;
    }
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

Boolean* Parser::parseBoolean(){
    Boolean* boolean = new Boolean(this->currentToken);
    return boolean;
}

PrefixExpression *Parser::parsePrefixOperator() {
  PrefixExpression *prefixExpression = new PrefixExpression();
  prefixExpression->setPrefixOperator(this->currentToken);
  this->nextToken();
  IExpression *rightExpression = this->parseExpression(Precedence::PREFIX);
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

IExpression* Parser::parseGroupedExpression(){
    this->nextToken();
    IExpression* expression = this->parseExpression(Precedence::LOWEST);
    if(this->peekToken.tokenType != TokenType::RIGHT_PARENTHESES){
        this->addError("No Right Parentheses");
        delete expression;
        return nullptr;
    }
    this->nextToken();
    return expression;
}

If* Parser::parseIfExpression(){
    if(this->peekToken.tokenType != TokenType::LEFT_PARENTHESES){
        this->addError("NO ( for if statement condition");
        return nullptr;
    }
    this->nextToken();
    IExpression* condition = this->parseExpression(Precedence::LOWEST);

    if(this->currentToken.tokenType != TokenType::RIGHT_PARENTHESES){
        this->addError("NO ) for if statement condition");
        delete condition;
        return nullptr;
    }
    this->nextToken();
    if(this->currentToken.tokenType != TokenType::LEFT_BRACE){
        this->addError("NO  { for if statement body ");
        delete condition;
        return nullptr;
    }
    this->nextToken();

    BlockStatement* consequence = this->parseBlock();
    if(this->currentToken.tokenType != TokenType::RIGHT_BRACE){
        this->addError("NO  } for if statement body ");
        delete consequence;
        delete condition;
        return nullptr;
    }
    If* ifExpression = new If(condition,consequence);
    this->nextToken();


    if(this->currentToken.tokenType != TokenType::ELSE){
        return ifExpression;
    }
    this->nextToken();

    if(this->currentToken.tokenType != TokenType::LEFT_BRACE){
        this->addError("NO  { for else statement body ");
        delete consequence;
        delete condition;
        delete ifExpression;
        return nullptr;
    }
    this->nextToken();
    BlockStatement* alternative = parseBlock();

    if(this->currentToken.tokenType != TokenType::RIGHT_BRACE){
        this->addError("NO  } for else statement body ");
        delete consequence;
        delete condition;
        delete ifExpression;
        delete alternative;
        return nullptr;
    }
    ifExpression->setAlternative(alternative);
    this->nextToken();
    return ifExpression;
}



template<typename T>
void freeCollection(std::vector<T*>& collection){
    for(auto& element : collection){
        delete element;
    }
}

FunctionLiteral* Parser::parseFunctionLiteral(){
    Token functionToken = this->currentToken;
    this->nextToken();
    if(this->currentToken.tokenType != TokenType::LEFT_PARENTHESES){
        return nullptr;
    }
    this->nextToken();
    std::vector<LValueIdentifier*> args = this->parseParameters();
    if(this->currentToken.tokenType != TokenType::RIGHT_PARENTHESES){
        freeCollection(args);
        return nullptr;
    }
    this->nextToken();
    if(this->currentToken.tokenType!= TokenType::LEFT_BRACE){
        freeCollection(args);
        return nullptr;
    }
    this->nextToken();
    BlockStatement* functionBlock = this->parseBlock();
    if(this->currentToken.tokenType != TokenType::RIGHT_BRACE){
        freeCollection(args);
        delete functionBlock;
        return nullptr;
    }
    FunctionLiteral* functionLiteral = new FunctionLiteral(functionToken,functionBlock,args);
    return functionLiteral;
}

std::vector<LValueIdentifier*> Parser::parseParameters(){
    std::vector<LValueIdentifier*>parameters;
    while (this->currentToken.tokenType != TokenType::RIGHT_PARENTHESES) {
        if(this->currentToken.tokenType != TokenType::COMMA){
            parameters.push_back(new LValueIdentifier(this->currentToken));
        }
        this->nextToken();
    }
    return parameters;
}

BlockStatement* Parser::parseBlock(){
    BlockStatement* blockStatement = new BlockStatement();
    blockStatement->setToken(this->currentToken);
    while (
        this->currentToken.tokenType != TokenType::RIGHT_BRACE
        && this->currentToken.tokenType != TokenType::END_OF_FILE
    ) {
        IStatement* statement = this->parseStatement();
        if(statement == nullptr){
            this->addError("ERRoR in parsing if body\n");
        } else {
            blockStatement->addStatement(statement);
        }
        this->nextToken();
    }
    return blockStatement;
}


FunctionCall* Parser::parseFunctionCallExpression(IExpression *leftExpression){
    std::vector<IExpression*>args = this->parseCallArguments();
    if(this->currentToken.tokenType != TokenType::RIGHT_PARENTHESES){
        freeCollection(args);
        return nullptr;
    }
    return new FunctionCall(TokenActions::createToken(TokenType::FUNCTION),leftExpression,args);
}

std::vector<IExpression*>Parser::parseCallArguments(){
    this->nextToken();
    std::vector<IExpression*> args ;
    while (this->currentToken.tokenType != TokenType::RIGHT_PARENTHESES
            && this->currentToken.tokenType != TokenType::END_OF_FILE) {
        if(this->currentToken.tokenType != TokenType::COMMA){
            args.push_back(this->parseExpression(Precedence::LOWEST));
        }
        this->nextToken();
    }
    return args;
}
