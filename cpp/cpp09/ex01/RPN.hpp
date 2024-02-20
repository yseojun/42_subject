#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
  RPN();
  RPN(const RPN &copy);
  RPN &operator=(const RPN &copy);
  std::stack<int> _stack;

public:
  RPN(const std::string &str);
  ~RPN();
  void calculate(std::string &str);
  void printStack();
  bool isOperator(const std::string &str);
};

#endif