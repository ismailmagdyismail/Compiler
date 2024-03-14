#include "lexer.hpp"
#include "../tokens/Token.hpp"
#include <iostream>
#include <string>

Lexer::Lexer(std::string sourceCode) {
  std::string filterdSourceCode = "";
  for (int i = 0; i < sourceCode.size(); i++) {
    if (sourceCode[i] != '\n' && sourceCode[i] != ' ') {
      filterdSourceCode += sourceCode[i];
    }
  }
  this->sourceCode = filterdSourceCode;
  this->currentIndex = 0;
}

bool Lexer::hasNext() { return this->currentIndex < this->sourceCode.size(); }

Token Lexer::nextToken() {
  if (!this->hasNext()) {
    return TokenActions::createToken("eof");
  }
  std::string tokenSoFar = std::string(1, this->sourceCode[this->currentIndex]);
  this->currentIndex++;
  while (this->currentIndex < this->sourceCode.size()) {
    if (TokenActions::isValidKeyword(tokenSoFar)) {
      return TokenActions::createToken(tokenSoFar);
    }
    const std::string nextToken =
        std::string(1, this->sourceCode[this->currentIndex]);
    if (TokenActions::isValidKeyword(nextToken)) {
      return TokenActions::createToken(tokenSoFar);
    }
    tokenSoFar += this->sourceCode[this->currentIndex];
    this->currentIndex++;
  }
  return TokenActions::createToken(tokenSoFar);
}
