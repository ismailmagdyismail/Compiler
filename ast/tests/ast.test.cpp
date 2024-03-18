#include "./ast.test.hpp"
#include "../Expressions/DummyExpression.hpp"
#include "../Expressions/IExpression.hpp"
#include "../Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../Statements/IStatement.hpp"
#include "../Statements/LValueIdentifier/LValueIdentifier.hpp"
#include "../Statements/LetStatment/LetStatement.hpp"
#include <iostream>

/*
    - Test Virtual destrcutors for all Node Types of the tree to make sure there
   is no memory leak
    - This have to be tested manually , verify console logs against desired
   output
*/
void testStatementNodes() {
  std::cout << "Testing StatmentNodes ....\n";
  IASTNode *statmentPointer = new LetStatement(
      {TokenActions::createToken("-1")}, new DummyExpression());
  delete statmentPointer;
  std::cout << "Done Testing StatmentNodes sucessfully ....\n";
}

void testExpressionNodes() {
  std::cout << "Testing ExpressionNodes ....\n";
  IASTNode *expressionPointer = new DummyExpression();
  delete expressionPointer;
  std::cout << "Done Testing ExpressionNodes sucessfully ....\n";
}

void testIdentifierNodes() {
  std::cout << "Testing IdentifierNodes ....\n";
  IStatement *lValue = new LValueIdentifier(TokenActions::createToken("-1"));
  IExpression *rValue =
      new RValueIdentifier(TokenActions::createToken("-1"), "-1");
  delete lValue;
  delete rValue;
  std::cout << "Done Testing IdentifierNodes sucessfully ....\n";
}

void AstTest::run() {
  testStatementNodes();
  testExpressionNodes();
  testIdentifierNodes();
}
