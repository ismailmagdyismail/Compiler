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
  assert(TokenActions::createToken("!").tokenType == TokenType::BANG);
  assert(TokenActions::createToken("if").tokenType == TokenType::IF);
  assert(TokenActions::createToken("else").tokenType == TokenType::ELSE);
  assert(TokenActions::createToken("true").tokenType == TokenType::TRUE);
  assert(TokenActions::createToken("false").tokenType == TokenType::FALSE);
  assert(TokenActions::createToken("return").tokenType == TokenType::RETURN);
  assert(TokenActions::createToken("*").tokenType == TokenType::ASTERISK);
  assert(TokenActions::createToken("/").tokenType == TokenType::SLASH);
  assert(TokenActions::createToken(">").tokenType == TokenType::GT);
  assert(TokenActions::createToken("<").tokenType == TokenType::LT);
  assert(TokenActions::createToken("10").tokenType == TokenType::INT);
  assert(TokenActions::createToken("").tokenType == TokenType::END_OF_FILE);
  assert(TokenActions::createToken("==").tokenType == TokenType::EQUAL);
  assert(TokenActions::createToken("!=").tokenType == TokenType::NOT_EQUAL);

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
  assert(TokenActions::isValidKeyword("!"));
  assert(!TokenActions::isValidKeyword("five"));
  assert(!TokenActions::isValidKeyword("10"));
  assert(!TokenActions::isValidKeyword("5"));
  assert(TokenActions::isValidKeyword("=="));
  assert(TokenActions::isValidKeyword("!="));

  std::cout << ">>> tokens types tested sucessfully , test passed ...\n";
}

void TokenTest::run() {
  testTokensCreation();
  testTokensTypes();
}
