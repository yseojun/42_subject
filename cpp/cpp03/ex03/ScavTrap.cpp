#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
};

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &src){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
};

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs){
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
};

void	ScavTrap::attack(const std::string& target){
	if (this->energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ScavTrap " << this->name
			<< " attacks " << target << ", causing " 
			<< this->attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name 
			<< " is out of energy!" << std::endl;
};

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name 
		<< " has entered in Gate keeper mode." << std::endl;
}

