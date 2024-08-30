#include "Token.hpp"
#include <cctype>
#include <exception>
#include <iostream>
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
    {"", {TokenType::END_OF_FILE, ""}},
    {"if", {TokenType::IF, "if"}},
    {"else", {TokenType::ELSE, "else"}},
    {"return", {TokenType::RETURN, "return"}},
    {"true", {TokenType::TRUE, "true"}},
    {"false", {TokenType::FALSE, "false"}},
    {"*", {TokenType::ASTERISK, "*"}},
    {"!", {TokenType::BANG, "!"}},
    {"<", {TokenType::LT, "<"}},
    {">", {TokenType::GT, ">"}},
    {"/", {TokenType::SLASH, "/"}},
    {"-", {TokenType::MINUS, "-"}},
    {"==", {TokenType::EQUAL, "=="}},
    {"!=", {TokenType::NOT_EQUAL, "!="}},
};

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

Token TokenActions::createToken(TokenType code) {
  switch (code) {
  case TokenType::LET:
    return {TokenType::LET, "let"};
  case TokenType::FUNCTION:
    return {TokenType::FUNCTION, "fn"};
  case TokenType::IF:
    return {TokenType::IF, "if"};
  case TokenType::ELSE:
    return {TokenType::ELSE, "else"};
  case TokenType::RETURN:
    return {TokenType::RETURN, "return"};
  case TokenType::TRUE:
    return {TokenType::TRUE, "true"};
  case TokenType::FALSE:
    return {TokenType::FALSE, "false"};
  case TokenType::EQUAL:
    return {TokenType::EQUAL, "=="};
  case TokenType::NOT_EQUAL:
    return {TokenType::NOT_EQUAL, "!="};
  case TokenType::ASSIGN:
    return {TokenType::ASSIGN, "="};
  case TokenType::PLUS:
    return {TokenType::PLUS, "+"};
  case TokenType::MINUS:
    return {TokenType::MINUS, "-"};
  case TokenType::ASTERISK:
    return {TokenType::ASTERISK, "*"};
  case TokenType::BANG:
    return {TokenType::BANG, "!"};
  case TokenType::SLASH:
    return {TokenType::SLASH, "/"};
  case TokenType::LT:
    return {TokenType::LT, "<"};
  case TokenType::GT:
    return {TokenType::GT, ">"};
  case TokenType::COMMA:
    return {TokenType::COMMA, ","};
  case TokenType::SEMI_COLON:
    return {TokenType::SEMI_COLON, ";"};
  case TokenType::LEFT_BRACE:
    return {TokenType::LEFT_BRACE, "{"};
  case TokenType::RIGHT_BRACE:
    return {TokenType::RIGHT_BRACE, "}"};
  case TokenType::LEFT_PARENTHESES:
    return {TokenType::LEFT_PARENTHESES, ")"};
  case TokenType::RIGHT_PARENTHESES:
    return {TokenType::RIGHT_PARENTHESES, ")"};
  }
  throw std::bad_exception();
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

std::string TokenActions::getTokenLiteralValue(TokenType code) {
  Token token = TokenActions::createToken(code);
  return token.literalValue;
}
