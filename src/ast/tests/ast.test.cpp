#include "./ast.test.hpp"
#include "../../parser/Parser.hpp"
#include "../Expressions/IExpression.hpp"
#include "../Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../Statements/IStatement.hpp"
#include "../Statements/LValueIdentifier/LValueIdentifier.hpp"
#include "../Statements/LetStatment/LetStatement.hpp"
#include "../Statements/StandAloneStatement/StandAloneStatement.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void testRValueIdentifier() {
  std::cout << "Testing RValueIdentifiers ....\n";
  RValueIdentifier r1(TokenActions::createToken("10"), "10");
  RValueIdentifier r2(TokenActions::createToken("x"), "x");
  assert(r1.toString() == "10");
  assert(r2.toString() == "x");
  std::cout << "Done Testing RValueIdentifiers sucessfully ....\n";
}

void testLValueIdentifier() {
  std::cout << "Testing LValueIdentifiers ....\n";
  LValueIdentifier l1(TokenActions::createToken("x"));
  assert(l1.toString() == "x");
  std::cout << "Done Testing LValueIdentifiers sucessfully ....\n";
}

void testLetStatement() {
  std::cout << "Testing LetStatement ....\n";
  LetStatement let1(
      {TokenActions::createToken("x")},
      new RValueIdentifier(TokenActions::createToken("10"), "10"));
  LetStatement let2({TokenActions::createToken("x")},
                    new RValueIdentifier(TokenActions::createToken("y"), "y"));
  assert(let1.toString() == "let x = 10");
  assert(let2.toString() == "let x = y");
  std::cout << "Done Testing LetStatement sucessfully ....\n";
}

void testStandAloneStatement() {
  // TODO
  std::cout << "Testing StandAloneStatements ....\n";
  // StandAloneStatement standAloneStatement();
  std::cout << "Done Testing StandAloneStatements sucessfully ....\n";
}

void testExpressionStatement() {
  // TODO
  // x = 10;
  std::cout << "Testing StandAloneStatements ....\n";
  // ExpressionStatement expressionStatement();
  std::cout << "Done Testing StandAloneStatements sucessfully ....\n";
}

void testEval(){
    std::cout << "Testing EVAL ....\n";
    struct TestStructure{
        Parser parser;
    };
    std::vector<TestStructure> tests;
    TestStructure t1 = {
        .parser = Parser({"5"}),
    };
    TestStructure t2 = {
        .parser = Parser({"true;false"}),
    };
    tests.push_back(t1);
    tests.push_back(t2);
    for(auto i : tests){
        AST ast = i.parser.parseProgram();
        IObject* objectValue = ast.eval();
        std::cout<<objectValue->value() <<" "<<objectValue->type()<<'\n';
        delete objectValue;
    }
    std::cout << "Done EVAL sucessfully ....\n";
}

void AstTest::run() {
  testLetStatement();
  testLValueIdentifier();
  testStandAloneStatement();
  testRValueIdentifier();
  testExpressionStatement();
  testEval();
}
