#include "Token.hpp"
#include <cctype>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, Token> keywords{
    {"=", {TokenType::ASSIGN, "="}},
    {"(", {TokenType::LEFT_PARENTHESES, "("}},
    {")", {TokenType::RIGHT_PARENTHESES, ")"}},
    {"{", {TokenType::LEFT_BRACE, "{"}},
    {"}", {TokenType::RIGHT_BRACE, "}"}},
    {",", {TokenType::COMMA, ","}},
    {";", {TokenType::SEMI_COLON, ";"}},
    {"+", {TokenType::PLUS, "+"}},
    {"fn", {TokenType::FUNCTION, "fn"}},
    {"let", {TokenType::LET, "let"}},
    {"", {TokenType::END_OF_FILE, ""}}};

bool TokenActions::isValidKeyword(std::string code) {
  return keywords.find(code) != keywords.end();
}

Token TokenActions::createToken(std::string code) {
  TokenType tokenType = TokenType::ILLEGAL;
  std::string literal = code;
  if (keywords.find(code) != keywords.end()) {
    tokenType = keywords[code].tokenType;
    literal = keywords[code].literalValue;
  } else if (isValidInteger(code)) {
    tokenType = TokenType::INT;
  } else if (TokenActions::isValidIdentifier(code)) {
    tokenType = TokenType::IDENTIFIER;
  }
  return {tokenType, literal};
}

bool TokenActions::isValidIdentifier(std::string identifier) {
  if (identifier.empty()) {
    return false;
  }
  if (!isalpha(identifier[0])) {
    return false;
  }
  for (int i = 0; i < identifier.size(); i++) {
    if ((!isalnum(identifier[i])) && identifier[i] != '_') {
      return false;
    }
  }
  return true;
}

bool TokenActions::isValidInteger(std::string number) {
  for (int i = 0; i < number.size(); i++) {
    if (!isdigit(number[i])) {
      return false;
    }
  }
  return true;
}
