#ifndef __LEXER_H
#define __LEXER_H

#include "../tokens/Token.hpp"
#include <string>

/**
- future versions may read source code from files and additional info for better
error messages (linenumber,filename,etc...)
*/

class Lexer {
public:
  Lexer(std::string sourceCode);
  Token nextToken();
  bool hasNext();

private:
  int currentIndex;
  std::string sourceCode;
  std::string getNextChar();
};

#endif
