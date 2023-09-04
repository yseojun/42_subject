#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>

template <typename T>
void	iter(T *arr, size_t length, void (*f)(T&));

#endif