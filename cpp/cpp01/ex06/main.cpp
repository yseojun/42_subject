#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
		std::cout << "Usage: ./ex06 <level>" << std::endl;
	else
		harl.complain(av[1]);
	return (0);
}