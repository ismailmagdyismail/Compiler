#include "./ast.test.hpp"
#include "../Expressions/DummyExpression.hpp"
#include "../Expressions/Expression.hpp"
#include "../Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../Statements/LValueIdentifier/LValueIdentifier.hpp"
#include "../Statements/LetStatment/LetStatement.hpp"
#include "../Statements/Statment.hpp"
#include <iostream>

/*
    - Test Virtual destrcutors for all Node Types of the tree to make sure there
   is no memory leak
    - This have to be tested manually , verify console logs against desired
   output
*/
void testStatementNodes() {
  std::cout << "Testing StatmentNodes ....\n";

  ASTNode *statmentPointer = new LetStatement({TokenActions::createToken("-1")},
                                              new DummyExpression());
  delete statmentPointer;
  std::cout << "Done Testing StatmentNodes sucessfully ....\n";
}

void testExpressionNodes() {
  std::cout << "Testing ExpressionNodes ....\n";
  ASTNode *expressionPointer = new DummyExpression();
  delete expressionPointer;
  std::cout << "Done Testing ExpressionNodes sucessfully ....\n";
}

void testIdentifierNodes() {
  std::cout << "Testing IdentifierNodes ....\n";
  Statement *lValue = new LValueIdentifier(TokenActions::createToken("-1"));
  Expression *rValue =
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
