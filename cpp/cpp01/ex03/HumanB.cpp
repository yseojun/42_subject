#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = NULL;
	std::cout << this->name << " is born!" << std::endl;
};

HumanB::~HumanB(){
	std::cout << this->name << " is dead!" << std::endl;
};

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name + " attack with bare hands" << std::endl;
	else
		std::cout << this->name + " attack with " + this->weapon->getType() << std::endl;
};

void	HumanB::setWeapon(Weapon &something)
{
	this->weapon = &something;
};