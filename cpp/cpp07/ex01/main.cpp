#include "iter.hpp"
#include <iostream>

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    std::cout << "intArray: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    return 0;
}
