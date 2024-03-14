#include "../Token.hpp"
#include "./Token.test.hpp"
#include <cassert>
#include <iostream>

void testTokensCreation() {
  std::cout << "-----------------------------------------------\n";
  std::cout << ">>> tokens creation testing  ...\n";
  assert(TokenActions::createToken("=").tokenType == TokenType::ASSIGN);
  assert(TokenActions::createToken("let").tokenType == TokenType::LET);
  assert(TokenActions::createToken("fn").tokenType == TokenType::FUNCTION);
  assert(TokenActions::createToken("(").tokenType ==
         TokenType::LEFT_PARENTHESES);
  assert(TokenActions::createToken(")").tokenType ==
         TokenType::RIGHT_PARENTHESES);
  assert(TokenActions::createToken("{").tokenType == TokenType::LEFT_BRACE);
  assert(TokenActions::createToken("}").tokenType == TokenType::RIGHT_BRACE);
  assert(TokenActions::createToken(",").tokenType == TokenType::COMMA);
  assert(TokenActions::createToken(";").tokenType == TokenType::SEMI_COLON);
  assert(TokenActions::createToken("!!").tokenType == TokenType::ILLEGAL);
  assert(TokenActions::createToken("5").tokenType == TokenType::INT);
  assert(TokenActions::createToken("10").tokenType == TokenType::INT);
  assert(TokenActions::createToken("").tokenType == TokenType::END_OF_FILE);
  assert(TokenActions::createToken("-1").tokenType == TokenType::END_OF_FILE);
  assert(TokenActions::createToken("eof").tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> tokens created sucessfully , test passed ...\n";
}

void testTokensTypes() {
  std::cout << "-----------------------------------------------\n";
  std::cout << ">>> tokens types testing  ...\n";
  assert(TokenActions::isValidKeyword("="));
  assert(TokenActions::isValidKeyword("let"));
  assert(TokenActions::isValidKeyword("fn"));
  assert(TokenActions::isValidKeyword("("));
  assert(TokenActions::isValidKeyword(")"));
  assert(TokenActions::isValidKeyword("+"));
  assert(TokenActions::isValidKeyword("{"));
  assert(TokenActions::isValidKeyword("}"));
  assert(TokenActions::isValidKeyword(","));
  assert(TokenActions::isValidKeyword(";"));
  assert(!TokenActions::isValidKeyword("!"));
  assert(!TokenActions::isValidKeyword("five"));
  assert(!TokenActions::isValidKeyword("10"));
  assert(!TokenActions::isValidKeyword("5"));
  std::cout << ">>> tokens types tested sucessfully , test passed ...\n";
}

void TokenTest::run() {
  testTokensCreation();
  testTokensTypes();
}
