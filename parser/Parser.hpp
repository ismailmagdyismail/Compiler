#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../lexer/lexer.hpp"
#include <vector>

class Parser {
public:
  Parser(Lexer lexer);
  // Parser(std::string sourceCode); // might use this as facade , initialize
  // lexer internally to encapsulate internal detail
  std::vector<Token> parseProgram();

private:
  std::vector<Token>
  parseLetStatement(); // TODO temporary return type until AST is ready
  void nextToken();
  Lexer lexer;
  Token currentToken;
};

#endif
