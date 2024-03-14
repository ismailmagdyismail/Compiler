#include "tokenFactory.hpp"
#include "token.hpp"
#include <string>

Token TokenFactory::createToken(std::string code) {
  TokenType tokenType = TokenType::ILLEGAL;
  std::string literal = "";

  if (code == "=") {
    tokenType = TokenType::ASSIGN;
  } else if (code == "(") {
    tokenType = TokenType::LEFT_PARENTHESES;
  } else if (code == ")") {
    tokenType = TokenType::RIGHT_PARENTHESES;
  } else if (code == "{") {
    tokenType = TokenType::LEFT_BRACE;
  } else if (code == "}") {
    tokenType = TokenType::RIGHT_BRACE;
  } else if (code == ",") {
    tokenType = TokenType::COMMA;
  } else if (code == ";") {
    tokenType = TokenType::SEMI_COLON;
  } else if (code == "+") {
    tokenType = TokenType::PLUS;
  } else if (code == "fn") {
    tokenType = TokenType::FUNCTION;
  } else if (code == "let") {
    tokenType = TokenType::LET;
  }
  return {tokenType, literal};
}
