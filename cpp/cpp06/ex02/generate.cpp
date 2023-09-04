#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static bool	tryCast(const Base &p, char type);

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
		std::cout << "'A'" << std::endl;
	else if (dynamic_cast< B * >(p))
		std::cout << "'B'" << std::endl;
	else if (dynamic_cast< C * >(p))
		std::cout << "'C'" << std::endl;
	else
		std::cout << "I don't know..." << std::endl;
}

void	identify(Base &p){
	if (tryCast(p, 'A') || tryCast(p, 'B') || tryCast(p, 'C'))
		return ;
}

static bool	tryCast(const Base &p, char type){
	try {
		if (type == 'A') {
			(void) dynamic_cast< const A& > (p);
		}
		else if (type == 'B'){
			(void) dynamic_cast< const B& > (p);
		}
		else if (type == 'C'){
			(void) dynamic_cast< const C& > (p);
		}

		std::cout << "'" << type << "'" << std::endl;

		return true;
	}
	catch (std::exception &){
		return false;		
	}
}