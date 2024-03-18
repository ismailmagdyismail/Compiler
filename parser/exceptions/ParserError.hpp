#include <exception>
#include <string>
class ParserError : public std::exception {
public:
  ParserError(const std::string &&errorMessage) {
    this->errorMessage = errorMessage;
  }
  ParserError(const std::string &errorMessage) {
    this->errorMessage = errorMessage;
  }
  const char *what() const noexcept override {
    return this->errorMessage.c_str();
  }

private:
  std::string errorMessage;
};
