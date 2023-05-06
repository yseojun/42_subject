#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &something): weapon(something){
	this->name = name;
	std::cout << this->name << " is born!" << std::endl;
};

HumanA::~HumanA(){
	std::cout << this->name << " is dead!" << std::endl;
};

void	HumanA::attack(void)
{
	std::cout << this->name + " attack with " 
		+ this->weapon.getType() << std::endl;
};