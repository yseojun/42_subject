#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main() {
    Base* generatedObject = generate();
    std::cout << std::endl;
    
    std::cout << "Identifying using pointer:" << std::endl;
    identify(generatedObject);

    std::cout << std::endl;

    std::cout << "Identifying using reference:" << std::endl;
    identify(*generatedObject);

    delete generatedObject;

    return 0;
}
