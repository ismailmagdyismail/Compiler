#ifndef __PRECEDENCE_HPP__
#define __PRECEDENCE_HPP__

#include "../../tokens/Token.hpp"
#include <map>

enum Precedence {
  LOWEST,
  EQUALS,
  NOT_EQUAL,
  LESS_GREATER,
  SUM,
  PRODUCT,
  PREFIX,
  CALL,
};
// std::map<TokenType, Precedence> tokensPrecedence;

// namespace TokensPrecedence {
// Precedence getTokenPrecedence(TokenType token);
// }

#endif
