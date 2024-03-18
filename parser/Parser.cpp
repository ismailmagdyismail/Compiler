#include "./Parser.hpp"
#include "./exceptions/ParserError.hpp"
#include <vector>

Parser::Parser(Lexer lexer) : lexer(lexer) { this->nextToken(); }

void Parser::nextToken() { currentToken = lexer.nextToken(); }

std::vector<Token> Parser::parseProgram() {
  std::vector<Token> tokens;
  if (this->currentToken.tokenType == TokenType::LET) {
    tokens = this->parseLetStatement();
  }
  nextToken();
  return tokens;
}

std::vector<Token> Parser::parseLetStatement() {
  if (this->currentToken.tokenType != TokenType::LET) {
    throw ParserError(
        "LET parsing error , Cannot run LET parser on A non LET token");
  }

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::IDENTIFIER) {
    throw ParserError(
        "LET parsing error , LET Token is not followed by an Identifier");
  }
  Token identifierToken = this->currentToken;

  this->nextToken();
  if (this->currentToken.tokenType != TokenType::ASSIGN) {
    throw ParserError("LET parsing error , LET Token doesn't have assign Token "
                      "following it ");
  }
  Token assignToken = this->currentToken;

  this->nextToken();
  if (this->currentToken.tokenType !=
          TokenType::INT && // TODO add parsing expression later , when
                            // expression parser is add
      this->currentToken.tokenType != TokenType::IDENTIFIER) {
    throw ParserError(
        "LET parsing error , LET Token doesn't have RValue assigned to it  ");
  }
  Token rValue = this->currentToken;

  std::vector<Token> parsedTokens;
  parsedTokens.push_back(TokenActions::createToken(TokenType::LET));
  parsedTokens.push_back(identifierToken);
  parsedTokens.push_back(assignToken);
  parsedTokens.push_back(rValue);

  return parsedTokens;
}
