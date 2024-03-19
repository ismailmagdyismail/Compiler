#include "./parser.test.hpp"
#include "../../lexer/lexer.hpp"
#include "../Parser.hpp"
#include "../exceptions/ParserError.hpp"
#include <cassert>
#include <iostream>
void testParsingLetStatement() {
  std::cout << ">>> Parser  tesing, testing LET Statment parsing .....\n";
  Parser parser = Parser({"let x = 10; let y =10; let z = x;"});
  AST ast = parser.parseProgram();
  assert(ast.size() == 3);
  assert(ast.getStatement(0)->getTokenLiteral() == "let");
  assert(ast.getStatement(1)->getTokenLiteral() == "let");
  assert(ast.getStatement(2)->getTokenLiteral() == "let");

  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}
void ParserTest::run() { testParsingLetStatement(); }
