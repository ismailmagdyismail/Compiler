#include "./parser.test.hpp"
#include "../../lexer/lexer.hpp"
#include "../Parser.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void testParsingLetStatement() {
  std::cout << ">>> Parser  tesing, testing LET Statment parsing .....\n";
  Parser parser = Parser({"let x = 10;"});
  std::vector<Token> tokens = parser.parseProgram();
  assert(tokens.size() == 4);
  assert(tokens[0].tokenType == TokenType::LET);
  assert(tokens[1].tokenType == TokenType::IDENTIFIER);
  assert(tokens[2].tokenType == TokenType::ASSIGN);
  assert(tokens[3].tokenType == TokenType::IDENTIFIER ||
         tokens[3].tokenType == TokenType::INT);

  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}
void ParserTest::run() { testParsingLetStatement(); }
