#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../ast/Expressions/BinaryExpression/BinaryExpression.hpp"
#include "../ast/Expressions/IExpression.hpp"
#include "../ast/Expressions/IntegerLiteral/IntegerLiteral.hpp"
#include "../ast/Expressions/PrefixExpression/PrefixExpression.hpp"
#include "../ast/Expressions/RValueIdentifier/RValueIdentifier.hpp"
#include "../ast/Statements/LetStatment/LetStatement.hpp"
#include "../ast/Statements/ReturnStatement/ReturnStatement.hpp"
#include "../ast/Statements/StandAloneStatement/StandAloneStatement.hpp"
#include "../ast/programAST/AST.hpp"
#include "../lexer/lexer.hpp"
#include "Precedence/Precedence.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Parser {
public:
  Parser(Lexer lexer);
  AST parseProgram();
  std::vector<std::string> getErrors();
  std::unordered_map<TokenType, std::function<IExpression *(IExpression *left)>>
      infixParsers;
  std::unordered_map<TokenType, std::function<IExpression *()>> prefixParser;

private:
  IStatement *parseStatement();
  LetStatement *parseLetStatement();
  ReturnStatement *parseReturnStatement();
  IExpression *parseExpression(Precedence precedence);
  StandAloneStatement *parseStandAloneStatement();
  RValueIdentifier *parseRValueIdentifier();
  IntegerLiteral *parseIntegerLiteral();
  PrefixExpression *parsePrefixOperator();
  BinaryExpression *parseBinaryExpression(IExpression *leftExpression);
  Precedence currentPrecedence();
  Precedence peekPrecedence();
  void nextToken();
  void addError(std::string errorMessage);
  std::vector<std::string> errors;
  Lexer lexer;
  Token currentToken;
  Token peekToken;
};

#endif
