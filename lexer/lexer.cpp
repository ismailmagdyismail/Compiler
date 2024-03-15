#include "lexer.hpp"
#include "../tokens/Token.hpp"
#include <string>

Lexer::Lexer(std::string sourceCode) {
  this->sourceCode = sourceCode;
  this->currentIndex = 0;
}

bool Lexer::hasNext() { return this->currentIndex < this->sourceCode.size(); }

/* TODO REFACTOR THIS, it is too procedural/sequence dependant, hard to read*/
Token Lexer::nextToken() {
  if (!this->hasNext()) {
    return TokenActions::createToken("");
  }
  std::string tokenSoFar = this->getNextChar();
  this->currentIndex++;
  while (hasNext()) {
    std::string nextChar = getNextChar();
    if (tokenSoFar == " " || tokenSoFar == "\n") {
      tokenSoFar = "";
      tokenSoFar += nextChar;
      this->currentIndex++;
      continue;
    }
    /// TODO abstract into more generic structur,since they are very similar
    if (TokenActions::isValidIdentifier(tokenSoFar)) {
      if (TokenActions::isValidIdentifier(tokenSoFar + nextChar)) {
        tokenSoFar += nextChar;
        this->currentIndex++;
        continue;
      }
      return TokenActions::createToken(tokenSoFar);
    }
    if (TokenActions::isValidKeyword(tokenSoFar)) {
      if (TokenActions::isValidKeyword(tokenSoFar + nextChar)) {
        tokenSoFar += nextChar;
        this->currentIndex++;
        continue;
      }
      return TokenActions::createToken(tokenSoFar);
    }
    if (TokenActions::isValidInteger(tokenSoFar)) {
      if (TokenActions::isValidInteger(tokenSoFar + nextChar)) {
        tokenSoFar += nextChar;
        this->currentIndex++;
        continue;
      }
      return TokenActions::createToken(tokenSoFar);
    }
    return {TokenType::ILLEGAL, tokenSoFar};
  }
  return TokenActions::createToken(tokenSoFar);
}

std::string Lexer::getNextChar() {
  return std::string(1, this->sourceCode[this->currentIndex]);
}
