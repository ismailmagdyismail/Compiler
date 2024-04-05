#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../ast/Expressions/IExpression.hpp"
#include "../ast/programAST/AST.hpp"
#include "../lexer/lexer.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Parser {
public:
  Parser(Lexer lexer);
  AST parseProgram();
  std::vector<std::string> getErrors();

private:
  IStatement *parseStatement();
  IStatement *parseLetStatement();
  IStatement *parseReturnStatement();
  IStatement *parseStandAloneStatement();
  IExpression *parseRvalueIdentifier();
  std::unordered_map<TokenType, std::function<IExpression *()>> infixParsers;
  std::unordered_map<TokenType, std::function<IExpression *()>> prefixParser;

  void nextToken();
  void addError(std::string errorMessage);
  std::vector<std::string> errors;
  Lexer lexer;
  Token currentToken;
};

#endif
