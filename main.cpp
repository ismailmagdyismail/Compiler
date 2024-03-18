#include "ast/tests/ast.test.hpp"
#include "lexer/tests/lexer.test.hpp"
#include "tokens/tests/Token.test.hpp"

int main() {
  TokenTest::run();
  LexerTest::run();
  AstTest::run();
}
