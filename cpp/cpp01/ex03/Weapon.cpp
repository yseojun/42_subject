#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << this->type << " Weapon created!" << std::endl;
};

Weapon::~Weapon(void)
{
	std::cout << this->type << " Weapon destroyed!" << std::endl;
};

const std::string	Weapon::getType(void)
{
	return (this->type);
};

void		Weapon::setType(std::string type)
{
	this->type = type;
};