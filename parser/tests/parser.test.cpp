#include "./parser.test.hpp"
#include "../../lexer/lexer.hpp"
#include "../Parser.hpp"
#include "../exceptions/ParserError.hpp"
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

void testParsingCorrectLetStatement() {
  std::cout
      << ">>> Parser tesing, testing Correct LET Statment parsing .....\n";
  Parser parser =
      Parser({"let x = 10; let y =10; let z = x;let foobar = 838383;"});
  AST ast = parser.parseProgram();
  assert(ast.size() == 4);
  assert(ast.getStatement(0)->getTokenLiteral() == "let");
  assert(ast.getStatement(0)->toString() == "let x = 10");
  assert(ast.getStatement(1)->getTokenLiteral() == "let");
  assert(ast.getStatement(1)->toString() == "let y = 10");
  assert(ast.getStatement(2)->getTokenLiteral() == "let");
  assert(ast.getStatement(2)->toString() == "let z = x");
  assert(ast.getStatement(3)->getTokenLiteral() == "let");
  assert(ast.getStatement(3)->toString() == "let foobar = 838383");

  assert(parser.getErrors().empty());
  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testParsingInCorrectLetStatement() {
  std::cout
      << ">>> Parser tesing, testing InCorrect LET Statment parsing .....\n";
  Parser parser1 = Parser({"let 10;"});
  AST ast = parser1.parseProgram();
  assert(!parser1.getErrors().empty());

  Parser parser2 = Parser({"let x 5;"});
  AST ast2 = parser2.parseProgram();
  assert(!parser2.getErrors().empty());

  Parser parser3 = Parser({"let = 10;"});
  AST ast3 = parser3.parseProgram();
  assert(!parser3.getErrors().empty());

  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testParsingCorrectReturnStatement() {
  std::cout
      << ">>> Parser tesing, testing Correct RETURN Statment parsing .....\n";
  Parser parser = Parser({"return 10; return x; return 1992"});
  AST ast = parser.parseProgram();
  assert(ast.size() == 3);
  assert(ast.getStatement(0)->getTokenLiteral() == "return");
  assert(ast.getStatement(0)->toString() == "return 10");
  assert(ast.getStatement(1)->getTokenLiteral() == "return");
  assert(ast.getStatement(1)->toString() == "return x");
  assert(ast.getStatement(2)->getTokenLiteral() == "return");
  assert(ast.getStatement(2)->toString() == "return 1992");
  assert(parser.getErrors().empty());
  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testParsingInCorrectReturnStatement() {
  std::cout
      << ">>> Parser tesing, testing InCorrect RETURN Statment parsing .....\n";
  Parser parser = Parser({"return ; "});
  AST ast = parser.parseProgram();
  assert(!parser.getErrors().empty());
  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testStandAloneRValueIdentifiers() {
  std::cout << ">>> Parser tesing, testing StandAloneRValueIdentifiers parsing "
               ".....\n";
  Parser parser1 = Parser({"x;"});
  AST ast1 = parser1.parseProgram();
  Parser parser2 = Parser({"10;"});
  AST ast2 = parser2.parseProgram();
  Parser parser3 = Parser({"10;x;"});
  AST ast3 = parser3.parseProgram();
  assert(ast1.size() == 1);
  assert(parser1.getErrors().empty());
  assert(ast1.getStatement(0)->toString() == "x");
  assert(ast2.size() == 1);
  assert(parser2.getErrors().empty());
  assert(ast2.getStatement(0)->toString() == "10");
  assert(ast3.size() == 2);
  assert(parser3.getErrors().empty());
  assert(ast3.getStatement(0)->toString() == "10");
  assert(ast3.getStatement(1)->toString() == "x");

  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testPrefixOperators() {
  std::cout << ">>> Parser tesing, testing Prefix Operators Expression parsing "
               ".....\n";
  Parser parser = Parser({"!10;-10;-15;!5"});
  AST ast = parser.parseProgram();
  assert(ast.size() == 4);
  assert(parser.getErrors().empty());
  assert(ast.getStatement(0)->toString() == "(!10)");
  assert(ast.getStatement(1)->toString() == "(-10)");
  assert(ast.getStatement(2)->toString() == "(-15)");
  assert(ast.getStatement(3)->toString() == "(!5)");
  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testBinaryOperators() {
  std::cout << ">>> Parser tesing, testing Binary Expression parsing "
               ".....\n";
  Parser parser = Parser({"-a*b;!-a;a+b+c;a*b*c;a*b/c;a+b/c;a+b*c+d/e-f;5 > 4 "
                          "== 3 < 4;5<4!=3>4; 3 + 4 * 5 == 3 * 1 + 4 * 5;"});
  AST ast = parser.parseProgram();

  assert(ast.size() == 10);
  assert(parser.getErrors().empty());
  assert(ast.getStatement(0)->toString() == "((-a)*b)");
  assert(ast.getStatement(1)->toString() == "(!(-a))");
  assert(ast.getStatement(2)->toString() == "((a+b)+c)");
  assert(ast.getStatement(3)->toString() == "((a*b)*c)");
  assert(ast.getStatement(4)->toString() == "((a*b)/c)");
  assert(ast.getStatement(5)->toString() == "(a+(b/c))");
  assert(ast.getStatement(6)->toString() == "(((a+(b*c))+(d/e))-f)");
  assert(ast.getStatement(7)->toString() == "((5>4)==(3<4))");
  assert(ast.getStatement(8)->toString() == "((5<4)!=(3>4))");
  assert(ast.getStatement(9)->toString() == "((3+(4*5))==((3*1)+(4*5)))");

  std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}

void testParsingBoolean(){
    std::cout << ">>> Parser tesing, testing Boolean Expression parsing "
                 ".....\n";

    Parser parser = Parser({"true;false;3>5==false;3<5==true;"});
    AST ast = parser.parseProgram();
    assert(ast.size() == 4);
    assert(parser.getErrors().empty());
    assert(ast.getStatement(0)->toString() == "true");
    assert(ast.getStatement(1)->toString() == "false");
    assert(ast.getStatement(2)->toString() == "((3>5)==false)");
    assert(ast.getStatement(3)->toString() == "((3<5)==true)");
    std::cout << ">>> Parser testing done sucessfully , test passed ...\n";
}


void ParserTest::run() {
  testParsingCorrectLetStatement();
  testParsingInCorrectLetStatement();
  testParsingCorrectReturnStatement();
  testParsingInCorrectReturnStatement();
  testStandAloneRValueIdentifiers();
  testPrefixOperators();
  testBinaryOperators();
  testParsingBoolean();
}
