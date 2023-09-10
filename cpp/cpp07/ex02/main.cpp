#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);

    // const test
    std::cout << "TEST 0" << std::endl;
    const Array<int> numbers2(MAX_VAL);
    std::cout << numbers2[0] << std::endl;
    // const test

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "TEST 1" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "TEST 2" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        tmp[0] = 10;
        std::cout << "tmp : " << tmp[0] << std::endl;
        std::cout << "numbers : " << numbers[0] << std::endl;
    }

    std::cout << "TEST 3" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "TEST 4" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "TEST 5" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "TEST 6" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        // std::cout << i << ": " << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}