#ifndef __STATMENT_HPP__
#define __STATMENT_HPP__

#include "../IASTNode.hpp"

/*
 - Compund Pattern
 - Act as a facade for its internal attributes
*/
class Statement : public ASTNode {
public:
  std::string getNodeType() override;
  virtual ~Statement();
};

#endif
