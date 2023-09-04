#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

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

template <typename T>
void	iter(T *arr, size_t length, void (*f)(T&)){
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}