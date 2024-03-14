#include "lexer.hpp"
#include "../tokens/token.hpp"
#include "../tokens/tokenFactory.hpp"
#include <string>

Lexer::Lexer(std::string sourceCode) {
  this->sourceCode = sourceCode;
  this->currentIndex = 0;
}

Token Lexer::nextToken() {
  std::string currentCode = "";
  for (; this->currentIndex < sourceCode.size(); this->currentIndex++) {
    currentCode += this->sourceCode[currentIndex];
    Token token = TokenFactory::createToken(currentCode);
    if (token.tokenType != TokenType::ILLEGAL) {
      this->currentIndex++;
      return token;
    }
  }
  return {TokenType::END_OF_FILE, ""};
}
