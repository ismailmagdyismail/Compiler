#include "lexer.hpp"
#include "../tokens/Token.hpp"
#include <iostream>
#include <string>

Lexer::Lexer(std::string sourceCode) {
  this->sourceCode = sourceCode;
  this->currentIndex = 0;
}

bool Lexer::hasNext() { return this->currentIndex < this->sourceCode.size(); }

Token Lexer::nextToken() {
  if (!this->hasNext()) {
    return TokenActions::createToken("");
  }
  std::string tokenSoFar = std::string(1, this->sourceCode[this->currentIndex]);
  this->currentIndex++;
  while (this->currentIndex < this->sourceCode.size()) {
    if (tokenSoFar == " " || tokenSoFar == "\n") {
      tokenSoFar = std::string(1, this->sourceCode[this->currentIndex]);
      currentIndex++;
      continue;
    }
    if (TokenActions::isValidKeyword(tokenSoFar)) {
      return TokenActions::createToken(tokenSoFar);
    }
    const std::string nextToken =
        std::string(1, this->sourceCode[this->currentIndex]);
    if (TokenActions::isValidKeyword(nextToken) || nextToken == " " ||
        nextToken == "\n") {
      return TokenActions::createToken(tokenSoFar);
    }
    tokenSoFar += this->sourceCode[this->currentIndex];
    this->currentIndex++;
  }
  return TokenActions::createToken(tokenSoFar);
}
