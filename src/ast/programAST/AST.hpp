#ifndef __AST_HPP__
#define __AST_HPP__

#include "../Statements/IStatement.hpp"
#include <vector>

class AST {
public:
  AST();
  AST(const AST &other);
  AST &operator=(const AST &other);
  void addStatement(IStatement *statement);
  IStatement *getStatement(int i); // TODO temp for testing
  unsigned int size();
  IObject* eval();
  ~AST();
private:
  std::vector<IStatement *> statements;
};

#endif
