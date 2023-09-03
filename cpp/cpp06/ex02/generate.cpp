#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void){
	Base *output;

	srand(time(0));
	int	tmp = rand() % 3;

	switch (tmp) {
		case 0:
			output = new A;
			std::cout << "Type 'A' generated!" << std::endl;
			break ;
		case 1:
			output = new B;
			std::cout << "Type 'B' generated!" << std::endl;
			break ;
		case 2:
			output = new C;
			std::cout << "Type 'C' generated!" << std::endl;
			break ;
		default:
			output = 0;
			break ;
	}
	return output;
}

void	identify(Base *p){
	if (dynamic_cast< A * >(p))
		std::cout << "Type 'A'" << std::endl;
	else if (dynamic_cast< B * >(p))
		std::cout << "Type 'B'" << std::endl;
	else if (dynamic_cast< C * >(p))
		std::cout << "Type 'C'" << std::endl;
	else
		std::cout << "I don't know..." << std::endl;
}

void	identify(Base &p){
	try {
        A& a = dynamic_cast<A&>(p);
		A aa(a);
        std::cout << "Type 'A'" << std::endl;
    } catch (const std::bad_cast& eA) {
        try {
            B& b = dynamic_cast<B&>(p);
			B bb(b);
            std::cout << "Type 'B'" << std::endl;
        } catch (const std::bad_cast& eB) {
            try {
                C& c = dynamic_cast<C&>(p);
				C cc(c);
                std::cout << "Type 'C'" << std::endl;
            } catch (const std::bad_cast& eC) {
                std::cout << "I don't know" << std::endl;
            }
        }
    }
}