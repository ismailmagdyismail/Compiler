#ifndef __LVALUEIDENTIFIER_HPP
#define __LVALUEIDENTIFIER_HPP

#include "../../../tokens/Token.hpp"
#include "../IStatement.hpp"

class LValueIdentifier : public IStatement {
public:
  LValueIdentifier(const LValueIdentifier &other);
  LValueIdentifier(Token token);
  LValueIdentifier &operator=(const LValueIdentifier &other);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual IStatement *clone() override;
  virtual ~LValueIdentifier();

private:
  Token token;
};

#endif
