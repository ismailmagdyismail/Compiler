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
  assert(TokenActions::createToken("").tokenType == TokenType::END_OF_FILE);
  assert(TokenActions::createToken("-1").tokenType == TokenType::END_OF_FILE);
  assert(TokenActions::createToken("eof").tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> tokens created sucessfully , test passed ...\n";
}

void testTokensTypes() {
  std::cout << "-----------------------------------------------\n";
  std::cout << ">>> tokens types testing  ...\n";
  assert(TokenActions::isValidKeyword("=") == true);
  assert(TokenActions::isValidKeyword("let") == true);
  assert(TokenActions::isValidKeyword("fn") == true);
  assert(TokenActions::isValidKeyword("(") == true);
  assert(TokenActions::isValidKeyword(")") == true);
  assert(TokenActions::isValidKeyword("+") == true);
  assert(TokenActions::isValidKeyword("{") == true);
  assert(TokenActions::isValidKeyword("}") == true);
  assert(TokenActions::isValidKeyword(",") == true);
  assert(TokenActions::isValidKeyword(";") == true);
  assert(TokenActions::isValidKeyword("!") == false);
  assert(TokenActions::isValidKeyword("five") == false);
  assert(TokenActions::isValidKeyword("10") == false);
  assert(TokenActions::isValidKeyword("5") == false);
  std::cout << ">>> tokens types tested sucessfully , test passed ...\n";
}

void TokenTest::run() {
  testTokensCreation();
  testTokensTypes();
}
