#include "../lexer.hpp"
#include "./lexer.test.hpp"
#include "cassert"
#include <iostream>

void testOnlyKeyWords();
void testKeyWordsAndILLEGALs();

void LexerTest::run() {
  testOnlyKeyWords();
  testKeyWordsAndILLEGALs();
}

void testOnlyKeyWords() {
  std::cout << "-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing only KeyWords.....\n";
  Lexer lexer("=+(){}");
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::PLUS);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void testKeyWordsAndILLEGALs() {
  std::cout << "-----------------------------------------------\n";
  std::cout
      << ">>> Lexer anaylisis tesing, testing keyWords and Identifiers.....\n";
  Lexer lexer("let five = 5;\nlet ten = 10;\n\nlet add = fn(x, y) {\nx+y\n};");
  assert(lexer.nextToken().tokenType == TokenType::LET);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::INT);
  assert(lexer.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer.nextToken().tokenType == TokenType::LET);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::INT);
  assert(lexer.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer.nextToken().tokenType == TokenType::LET);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::FUNCTION);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::COMMA);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::PLUS);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::SEMI_COLON);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}
