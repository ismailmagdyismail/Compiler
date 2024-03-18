#ifndef __IDENTIFIER_HPP
#define __IDENTIFIER_HPP

#include "../../../tokens/Token.hpp"
#include "../IASTNode.hpp"

class Identifier : public ASTNode {
public:
  Identifier(Token token);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual ~Identifier();

private:
  Token token;
};

#endif
