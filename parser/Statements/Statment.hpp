#ifndef __STATMENT_HPP__
#define __STATMENT_HPP__

#include "../IAST.hpp"

class StatmentNode : public ASTNode {
public:
  virtual std::string getTokenLiteral() override;
};

#endif
