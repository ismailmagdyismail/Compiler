#include "./Expression.hpp"
#include <iostream>

Expression::~Expression() {
  std::cout << "Deleting expression baseNode\n"; // debugging
}
