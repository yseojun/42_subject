#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: Could not open file." << std::endl;
    return EXIT_FAILURE;
  }

  BitcoinExchange btc("data.csv");
  btc.processInput(argv[1]);

  return EXIT_SUCCESS;
}
