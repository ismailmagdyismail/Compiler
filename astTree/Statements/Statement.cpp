#include "./Statment.hpp"
#include <iostream>

std::string Statement::getNodeType() { return "StatementNode"; }

Statement::~Statement() {
  std::cout << "Deleting Statement baseNode \n"; // Deubugging
}
