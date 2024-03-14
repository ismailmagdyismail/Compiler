#include "./tokens.test.hpp"
#include "../token.hpp"
#include "./../tokenFactory.hpp"
#include <cassert>
#include <iostream>

void TokensTests::testTokensCreation() {
  std::cout << "tokens creation testing  ...\n";
  assert(TokenFactory::createToken("=").tokenType == TokenType::ASSIGN);
  assert(TokenFactory::createToken("let").tokenType == TokenType::LET);
  assert(TokenFactory::createToken("fn").tokenType == TokenType::FUNCTION);
  assert(TokenFactory::createToken("(").tokenType ==
         TokenType::LEFT_PARENTHESES);
  assert(TokenFactory::createToken(")").tokenType ==
         TokenType::RIGHT_PARENTHESES);
  assert(TokenFactory::createToken("{").tokenType == TokenType::LEFT_BRACE);
  assert(TokenFactory::createToken("}").tokenType == TokenType::RIGHT_BRACE);
  assert(TokenFactory::createToken(",").tokenType == TokenType::COMMA);
  assert(TokenFactory::createToken(";").tokenType == TokenType::SEMI_COLON);
  assert(TokenFactory::createToken("!!").tokenType == TokenType::ILLEGAL);
  std::cout << "tokens created sucessfully , test passed ...\n";
}
