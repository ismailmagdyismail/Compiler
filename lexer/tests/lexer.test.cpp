#include "../lexer.hpp"
#include "./lexer.test.hpp"
#include "cassert"
#include <iostream>

void testOnlyKeyWords() {
  std::string code = "=+(){}";
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing only KeyWords .....\n";
  std::cout << "testing " << code << '\n';

  Lexer lexer(code);
  assert(lexer.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer.nextToken().tokenType == TokenType::PLUS);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_PARENTHESES);
  assert(lexer.nextToken().tokenType == TokenType::LEFT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::RIGHT_BRACE);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void testKeyWordsAndIdentifiers() {
  std::string code =
      "let five = 5;\nlet ten = 10;\n\nlet add = fn(x, y) {\n x + y\n};";
  std::cout << "\n-----------------------------------------------\n";
  std::cout
      << ">>> Lexer anaylisis tesing, testing keyWords and Identifiers...\n";
  std::cout << "testing " << code << '\n';
  Lexer lexer(code);

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
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void testValidIdentifiers() {
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing Valid Identifiers.....\n";
  std::cout << "Testing five\n";
  Lexer lexer1("five");
  assert(lexer1.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer1.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << "Testing five55\n";
  Lexer lexer2("five55");
  assert(lexer2.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer2.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void testInvalidIdentifiers() {
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing Invalid Identifiers.....\n";
  std::cout << "Testing five!\n";
  Lexer lexer("five!");
  assert(lexer.nextToken().tokenType == TokenType::ILLEGAL);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void LexerTest::run() {
  testOnlyKeyWords();
  testKeyWordsAndIdentifiers();
  testValidIdentifiers();
  testInvalidIdentifiers();
}
