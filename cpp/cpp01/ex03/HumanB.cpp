#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
};

void	HumanB::attack(void)
{
	std::cout << this->name + " attack with "
		+ this->weapon->getType() << std::endl;
};

void	HumanB::setWeapon(Weapon &something)
{
	this->weapon = &something;
};