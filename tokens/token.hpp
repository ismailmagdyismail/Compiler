#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

enum class TokenType {

  END_OF_FILE,
  ILLEGAL,

  // Keywords
  LET,
  FUNCTION,
  IF,
  ELSE,
  RETURN,
  TRUE,
  FALSE,
  EQUAL,
  NOT_EQUAL,

  // Identfiers & literals
  IDENTIFIER,
  INT,

  // Operators
  ASSIGN,
  PLUS,
  MINUS,
  ASTERISK,
  BANG,
  SLASH,
  LT,
  GT,

  // Delimters
  COMMA,
  SEMI_COLON,

  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_PARENTHESES,
  RIGHT_PARENTHESES,
};

struct Token {
  TokenType tokenType;
  std::string literalValue;
};

namespace TokenActions {
Token createToken(std::string code);
bool isValidKeyword(std::string code);
bool isValidIdentifier(std::string identifier);
bool isValidInteger(std::string number);
} // namespace TokenActions

#endif
