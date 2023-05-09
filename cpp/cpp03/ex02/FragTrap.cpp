#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap Default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap Name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src){
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs){
	std::cout << "FragTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target){
	if (this->energyPoints > 0)
	{
		energyPoints--;
		std::cout << "FragTrap " << this->name
			<< " attacks " << target << ", causing " 
			<< this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->name 
			<< " is out of energy!" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name
		<< " wants to high five!" << std::endl;
}