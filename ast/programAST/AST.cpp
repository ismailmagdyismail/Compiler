#include "./AST.hpp"
#include <exception>
#include <iostream>

AST::AST() {}

AST::AST(const AST &other) {
  for (int i = 0; i < other.statements.size(); i++) {
    this->statements.push_back(other.statements[i]->clone());
  }
}

AST &AST::operator=(const AST &other) {
  for (int i = 0; i < other.statements.size(); i++) {
    this->statements.push_back(other.statements[i]->clone());
  }
  return *this;
}

void AST::addStatement(IStatement *statement) {
  this->statements.push_back(statement);
}

IStatement *AST::getStatement(int i) {
  if (i >= this->statements.size()) {
    throw std::exception();
  }
  return this->statements[i];
}

unsigned int AST::size() { return this->statements.size(); }

AST::~AST() {
  for (auto &statement : this->statements) {
    delete statement;
  }
}
