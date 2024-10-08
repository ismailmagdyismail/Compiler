#ifndef __RVALUEIDENTIFIER_HPP
#define __RVALUEIDENTIFIER_HPP

#include "../../../tokens/Token.hpp"
#include "../IExpression.hpp"
#include <string>

/*
    - a Leaf Node of the  tree (Compund pattern)
*/
class RValueIdentifier : public IExpression {
public:
  RValueIdentifier(const RValueIdentifier &other);
  RValueIdentifier(Token token, std::string value);
  RValueIdentifier &operator=(const RValueIdentifier &other);
  virtual std::string getTokenLiteral() override;
  virtual std::string getNodeType() override;
  virtual std::string getValueLiteral() override;
  virtual std::string toString() override;
  virtual IObject* objectValue() override;
  virtual IExpression *clone() override;
  virtual ~RValueIdentifier();

private:
  Token token;
  std::string value;
};

#endif
