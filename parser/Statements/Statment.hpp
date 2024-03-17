#ifndef __STATMENT_HPP__
#define __STATMENT_HPP__

#include "../IASTNode.hpp"

class Statement : public ASTNode {
public:
  virtual std::string getNodeType() override;
  virtual ~Statement();
};

#endif
