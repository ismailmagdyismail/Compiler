#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../ast/programAST/AST.hpp"
#include "../lexer/lexer.hpp"
#include <string>
#include <vector>

class Parser {
public:
  Parser(Lexer lexer);
  AST parseProgram();
  std::vector<std::string> getErrors();

private:
  IStatement *parseStatement();
  IStatement *parseLetStatement();
  IStatement *parseReturnExpression();
  void nextToken();
  void addError(std::string errorMessage);
  std::vector<std::string> errors;
  Lexer lexer;
  Token currentToken;
};

#endif
