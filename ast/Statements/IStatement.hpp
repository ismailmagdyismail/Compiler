#ifndef __STATMENT_HPP__
#define __STATMENT_HPP__

#include "../IASTNode.hpp"

/*
 - Compund Pattern
 - Act as a facade for its internal attributes
*/
class IStatement : public IASTNode {
public:
  virtual IStatement *clone() = 0;
  virtual ~IStatement();
};

#endif
