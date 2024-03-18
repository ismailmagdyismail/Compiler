#include "./IExpression.hpp"
#include <iostream>

IExpression::~IExpression() {
  std::cout << "Deleting expression baseNode\n"; // debugging
}
