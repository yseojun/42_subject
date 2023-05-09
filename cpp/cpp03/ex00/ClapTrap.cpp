#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name)
	:name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap name constructor called" << std::endl;
};

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &src){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs){
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
};

void	ClapTrap::attack(const std::string& target){
	if (this->energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << this->name
			<< " attacks " << target << ", causing " 
			<< this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name 
			<< " is out of energy!" << std::endl;
};

void	ClapTrap::takeDamage(unsigned int amount){
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name
		<< " takes " << amount << " points of damage!" << std::endl;
};

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints > 0)
	{
		energyPoints--;
		this->hitPoints += amount;
		if (this->hitPoints > 10)
			this->hitPoints = 10;
		std::cout << "ClapTrap " << this->name
			<< " is repaired for " << amount << " points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name 
			<< " is out of energy!" << std::endl;
};