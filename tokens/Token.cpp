#include "Token.hpp"
#include <cctype>
#include <iostream>
#include <string>

bool isValidIdenfier(std::string identifier) {
  for (int i = 0; i < identifier.size(); i++) {
    if (!isalnum(identifier[i])) {
      return false;
    }
  }
  return true;
}

Token TokenActions::createToken(std::string code) {
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
  } else if (code == "-1" || code == "eof" || code == "") {
    tokenType = TokenType::END_OF_FILE;
  } else if (isValidIdenfier(code)) {
    tokenType = TokenType::IDENTIFIER;
  }
  return {tokenType, literal};
}

bool TokenActions::isValidKeyword(std::string code) {
  const TokenType tokenType = createToken(code).tokenType;
  return tokenType == TokenType::LET || tokenType == TokenType::FUNCTION ||
         tokenType == TokenType::ASSIGN || tokenType == TokenType::COMMA ||
         tokenType == TokenType::SEMI_COLON || tokenType == TokenType::PLUS ||
         tokenType == TokenType::LEFT_BRACE ||
         tokenType == TokenType::RIGHT_BRACE ||
         tokenType == TokenType::LEFT_PARENTHESES ||
         tokenType == TokenType::RIGHT_PARENTHESES;
}
