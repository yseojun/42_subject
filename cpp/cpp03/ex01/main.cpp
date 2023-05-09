#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("a");
	ScavTrap me("seojyang");

	std::cout << std::endl;

	a.attack("seojyang");
	me.takeDamage(0);
	a.beRepaired(5);
	me.attack("a");
	a.takeDamage(5);
	me.guardGate();

	std::cout << std::endl;
};