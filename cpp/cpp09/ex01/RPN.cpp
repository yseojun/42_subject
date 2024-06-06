#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) { *this = copy; }

RPN &RPN::operator=(const RPN &copy) {
  (void)copy;
  return (*this);
}

RPN::RPN(const std::string &str) {
  std::stringstream ss(str);
  std::string tmp;
  while (ss >> tmp) {
    if (isOperator(tmp)) {
      calculate(tmp);
    } else if (tmp.length() == 1 && isdigit(tmp[0])) {
      _stack.push(tmp[0] - '0');
    } else {
      throw std::invalid_argument("Error: Invalid input.");
    }
  }
  printStack();
}

bool RPN::isOperator(const std::string &str) {
  if (str == "+" || str == "-" || str == "*" || str == "/")
    return (true);
  return (false);
}

void RPN::calculate(std::string &str) {
  int a;
  int b;
  int res;

  if (_stack.size() < 2) {
    throw std::invalid_argument("Error");
  }
  a = _stack.top();
  _stack.pop();
  b = _stack.top();
  _stack.pop();
  if (str == "+") {
    res = b + a;
  } else if (str == "-") {
    res = b - a;
  } else if (str == "*") {
    res = b * a;
  } else if (str == "/") {
    if (a == 0) {
      throw std::invalid_argument("Error: Division by zero.");
    }
    res = b / a;
  }
  _stack.push(res);
}

void RPN::printStack() {
  if (_stack.size() != 1) {
    throw std::invalid_argument("Error");
  }
  std::cout << _stack.top() << std::endl;
}
