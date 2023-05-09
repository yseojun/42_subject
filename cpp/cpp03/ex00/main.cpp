#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap me("seojyang");

	std::cout << std::endl;

	a.attack("seojyang");
	me.takeDamage(0);
	a.beRepaired(5);
	me.attack("a");
	a.takeDamage(5);

	std::cout << std::endl;
};