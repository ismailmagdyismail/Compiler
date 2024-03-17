#include "./Expression.hpp"
#include <iostream>

std::string Expression::getNodeType() { return "ExpressionNode"; }

Expression::~Expression() {
  std::cout << "Deleting expression baseNode"; // debugging
}
