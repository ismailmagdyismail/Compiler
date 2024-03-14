#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

enum class TokenType {

  END_OF_FILE,
  ILLEGAL,

  // Keywords
  LET,
  FUNCTION,

  // Identfiers & literals
  IDENTIFIER,
  INT,

  // Operators
  ASSIGN,
  PLUS,

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

#endif
