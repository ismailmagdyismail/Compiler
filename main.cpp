#include "astTree/tests/ast.test.hpp"
#include "lexer/tests/lexer.test.hpp"
#include "tokens/tests/Token.test.hpp"
#include <iostream>

int main() {
  TokenTest::run();
  LexerTest::run();
  AstTest::run();
}
