#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../ast/programAST/AST.hpp"
#include "../lexer/lexer.hpp"

class Parser {
public:
  Parser(Lexer lexer);
  AST parseProgram();

private:
  IStatement *parseStatement();
  IStatement *parseLetStatement();
  void nextToken();
  Lexer lexer;
  Token currentToken;
};

#endif
