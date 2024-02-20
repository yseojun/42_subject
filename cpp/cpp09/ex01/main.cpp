#include "RPN.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: Bad input Size!" << std::endl;
    return (EXIT_FAILURE);
  }
  try {
    RPN rpn(av[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}