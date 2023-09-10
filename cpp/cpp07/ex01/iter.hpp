#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
void	iter(T *arr, size_t length, void (*f)(T&)){
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

#endif