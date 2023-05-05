#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &something): weapon(something){
	this->name = name;
	this->weapon = something;
};

void	HumanA::attack(void)
{
	std::cout << this->name + " attack with " 
		+ this->weapon.getType() << std::endl;
};