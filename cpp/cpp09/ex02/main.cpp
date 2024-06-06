#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <numbers...>" << std::endl;
    return 1;
  }

  std::vector<int> vecNumbers;
  std::deque<int> deqNumbers;
  for (int i = 1; i < argc; ++i) {
    int num = std::atoi(argv[i]);
    if (num < 0) {
      std::cout << "Error: Negative numbers are not allowed: " << num
                << std::endl;
      return 1;
    }
    vecNumbers.push_back(num);
    deqNumbers.push_back(num);
  }

  PmergeMe sorter;

  std::cout << "Before (vector): ";
  sorter.print(vecNumbers);

  clock_t startVec = clock();
  sorter.sort(vecNumbers);
  clock_t endVec = clock();

  std::cout << "After (vector): ";
  sorter.print(vecNumbers);

  std::cout << std::endl;

  std::cout << "Before (deque): ";
  sorter.print(deqNumbers);

  clock_t startDeq = clock();
  sorter.sort(deqNumbers);
  clock_t endDeq = clock();

  std::cout << "After (deque): ";
  sorter.print(deqNumbers);

  std::cout << std::endl;
  std::cout << "-----------------------------------------" << std::endl
            << std::endl;
  std::cout << "Time to process a range of " << vecNumbers.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(6)
            << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC
            << " seconds" << std::endl;
  std::cout << "Time to process a range of " << deqNumbers.size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(6)
            << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC
            << " seconds" << std::endl;

  return 0;
}
