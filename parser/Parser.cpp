#include "./Parser.hpp"
#include "../ast/Expressions/IExpression.hpp"
#include "../ast/Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../ast/Statements/LetStatment/LetStatement.hpp"
#include "./exceptions/ParserError.hpp"

Parser::Parser(Lexer lexer) : lexer(lexer) { this->nextToken(); }

void Parser::nextToken() { currentToken = lexer.nextToken(); }

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
  return nullptr;
}

IStatement *Parser::parseLetStatement() {
  // TODO add parsing expression later , when
  // expression parser is add
  if (this->currentToken.tokenType != TokenType::LET) {
    return nullptr;
  }

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::IDENTIFIER) {
    return nullptr;
  }
  Token identifierToken = this->currentToken;

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::ASSIGN) {
    return nullptr;
  }

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::INT &&
      this->currentToken.tokenType != TokenType::IDENTIFIER) {
    return nullptr;
  }
  Token rValueToken = this->currentToken;
  LValueIdentifier lValueIdentifier = LValueIdentifier(identifierToken);
  IExpression *expression =
      new RValueIdentifier(rValueToken, rValueToken.literalValue);
  return new LetStatement(lValueIdentifier, expression);
}
