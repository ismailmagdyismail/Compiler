#ifndef __LEXER_H
#define __LEXER_H

#include "../tokens/token.hpp"
#include <string>

/**
- Current version is treaing source code as Pure text
- future versions may read source code from files and additional info for better
error messages (linenumber,filename,etc...)
*/

class Lexer {
public:
  Token nextToken();
  Lexer(std::string sourceCode);

private:
  int currentIndex;
  std::string sourceCode;
};

#endif
