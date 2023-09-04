#include <iostream>
#include <stdexcept>

#include "Array.hpp"

int main() {
    try {
        // Testing the Array class template
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
        }

        std::cout << "Element at index 2: " << intArray[2] << std::endl;
        std::cout << "Array size: " << intArray.size() << std::endl;

        Array<int> copyArray = intArray; // Copy constructor
        copyArray[2] = 99; // Modifying the copy does not affect the original

        std::cout << "Copied element at index 2: " << copyArray[2] << std::endl;
        std::cout << "Original element at index 2: " << intArray[2] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
