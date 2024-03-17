#include "lexer.hpp"
#include "../tokens/Token.hpp"
#include <string>

std::string filterSourceCode(std::string);

Lexer::Lexer(std::string sourceCode) {
  this->sourceCode = filterSourceCode(sourceCode);
  this->currentIndex = 0;
}

bool Lexer::hasNext() { return this->currentIndex < this->sourceCode.size(); }

/*
- TODO REFACTOR THIS, it is too procedural/sequence dependant, hard to read
- Shittest code I have ever written !
*/
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

std::string filterSourceCode(std::string sourceCode) {
  int start = sourceCode.size();
  for (int i = 0; i < sourceCode.size(); i++) {
    if (sourceCode[i] != ' ' && sourceCode[i] != '\n') {
      start = i;
      break;
    }
  }
  int end = 0;
  for (int i = sourceCode.size() - 1; i >= 0; i--) {
    if (sourceCode[i] != ' ' || sourceCode[i] != '\n') {
      end = i;
      break;
    }
  }
  std::string filteredCode;
  for (int i = start; i <= end; i++) {
    filteredCode += sourceCode[i];
  }
  return filteredCode;
}
