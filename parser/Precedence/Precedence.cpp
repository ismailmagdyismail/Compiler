#include "Precedence.hpp"

std::map<TokenType, Precedence> tokensPrecedence = {
    {TokenType::PLUS, SUM},         {TokenType::MINUS, SUM},
    {TokenType::ASTERISK, PRODUCT}, {TokenType::SLASH, PRODUCT},
    {TokenType::LT, LESS_GREATER},  {TokenType::GT, LESS_GREATER},
    {TokenType::EQUAL, EQUALS},     {TokenType::NOT_EQUAL, NOT_EQUAL},
    {TokenType::LEFT_PARENTHESES,CALL}
};

Precedence TokensPrecedence::getTokenPrecedence(TokenType token) {
  return tokensPrecedence[token];
}
