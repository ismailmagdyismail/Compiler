#include "ast/tests/ast.test.hpp"
#include "lexer/tests/lexer.test.hpp"
#include "parser/tests/parser.test.hpp"
#include "tokens/tests/Token.test.hpp"

int main() {
  TokenTest::run();
  LexerTest::run();
  AstTest::run();
  ParserTest::run();
}
