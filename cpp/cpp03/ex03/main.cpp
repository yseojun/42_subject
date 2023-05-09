#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("a");
	DiamondTrap me("seojyang");

	std::cout << std::endl;

	a.attack("seojyang");
	me.takeDamage(30);
	a.beRepaired(12);
	a.whoAmI();
	me.whoAmI();

	std::cout << std::endl;
};