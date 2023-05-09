#include "FragTrap.hpp"

int main()
{
	FragTrap a("a");
	FragTrap me("seojyang");

	std::cout << std::endl;

	a.attack("seojyang");
	me.takeDamage(0);
	a.beRepaired(5);
	me.attack("a");
	a.takeDamage(5);
	me.highFivesGuys();

	std::cout << std::endl;
};