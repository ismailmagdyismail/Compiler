#include "./IStatement.hpp"
#include <iostream>

std::string IStatement::getNodeType() { return "StatementNode"; }

IStatement::~IStatement() {
  std::cout << "Deleting Statement baseNode \n"; // Deubugging
}
