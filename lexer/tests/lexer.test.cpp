#include "../lexer.hpp"
#include "./lexer.test.hpp"
#include "cassert"
#include <iostream>

void testLexerParsing();

void LexerTest::run() { testLexerParsing(); }

void testLexerParsing() {
  std::cout << "-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing .....\n";
  Lexer lexer("=+(){}");
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::PLUS);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_BRACE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}
