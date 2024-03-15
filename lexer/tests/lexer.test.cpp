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
void testSpaces() {
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing spacing .....\n";

  std::string code = "let a = b;";
  std::cout << "testing " << code << '\n';
  Lexer lexer1(code);
  assert(lexer1.nextToken().tokenType == TokenType::LET);
  assert(lexer1.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer1.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer1.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer1.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer1.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "let a + b ;";
  std::cout << "testing " << code << '\n';
  Lexer lexer2(code);
  assert(lexer2.nextToken().tokenType == TokenType::LET);
  assert(lexer2.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer2.nextToken().tokenType == TokenType::PLUS);
  assert(lexer2.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer2.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer2.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "fn(a,b){}";
  std::cout << "testing " << code << '\n';
  Lexer lexer3(code);
  assert(lexer3.nextToken().tokenType == TokenType::FUNCTION);
  assert(lexer3.nextToken().tokenType == TokenType::LEFT_PARENTHESES);
  assert(lexer3.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer3.nextToken().tokenType == TokenType::COMMA);
  assert(lexer3.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer3.nextToken().tokenType == TokenType::RIGHT_PARENTHESES);
  assert(lexer3.nextToken().tokenType == TokenType::LEFT_BRACE);
  assert(lexer3.nextToken().tokenType == TokenType::RIGHT_BRACE);

  code = "let a=b;";
  std::cout << "testing " << code << '\n';
  Lexer lexer4(code);
  assert(lexer4.nextToken().tokenType == TokenType::LET);
  assert(lexer4.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer4.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer4.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer4.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer4.nextToken().tokenType == TokenType::END_OF_FILE);

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

void testingNumbers() {
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing Numbers.....\n";
  std::string code = "55";
  std::cout << "Testing " << code << '\n';
  Lexer lexer(code);
  assert(lexer.nextToken().tokenType == TokenType::INT);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "five5 55 5 = 5;";
  std::cout << "Testing " << code << '\n';
  Lexer lexer2(code);
  assert(lexer2.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer2.nextToken().tokenType == TokenType::INT);
  assert(lexer2.nextToken().tokenType == TokenType::INT);
  assert(lexer2.nextToken().tokenType == TokenType::ASSIGN);
  assert(lexer2.nextToken().tokenType == TokenType::INT);
  assert(lexer2.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer2.nextToken().tokenType == TokenType::END_OF_FILE);
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
  std::string code = "five!";
  std::cout << "Testing " << code << '\n';
  Lexer lexer(code);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::ILLEGAL);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "five!!";
  std::cout << "Testing " << code << '\n';
  Lexer lexer2(code);
  assert(lexer2.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer2.nextToken().tokenType == TokenType::ILLEGAL);
  assert(lexer2.nextToken().tokenType == TokenType::ILLEGAL);
  assert(lexer2.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "5five;five"; /// TODO make this case invalid
  std::cout << "Testing " << code << '\n';
  Lexer lexer3(code);
  assert(lexer3.nextToken().tokenType == TokenType::INT);
  assert(lexer3.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer3.nextToken().tokenType == TokenType::SEMI_COLON);
  assert(lexer3.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer3.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}

void testingNoSpacesBetweenKeywords() {
  std::cout << "\n-----------------------------------------------\n";
  std::cout << ">>> Lexer anaylisis tesing, testing Invalid Identifiers.....\n";
  std::string code = "fnfive";
  std::cout << "Testing " << code << '\n';
  Lexer lexer(code);
  assert(lexer.nextToken().tokenType == TokenType::IDENTIFIER);
  assert(lexer.nextToken().tokenType == TokenType::END_OF_FILE);

  code = "fn";
  std::cout << "Testing " << code << '\n';
  Lexer lexer2(code);
  assert(lexer2.nextToken().tokenType == TokenType::FUNCTION);
  assert(lexer2.nextToken().tokenType == TokenType::END_OF_FILE);
  std::cout << ">>> Lexer anaylisis done sucessfully , test passed ...\n";
}
void LexerTest::run() {
  testOnlyKeyWords();
  testKeyWordsAndIdentifiers();
  testValidIdentifiers();
  testInvalidIdentifiers();
  testSpaces();
  testingNoSpacesBetweenKeywords();
}
