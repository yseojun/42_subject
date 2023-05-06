#include "Zombie.hpp"

Zombie::Zombie(){
	this->name = "Zombie";
	std::cout << "Normal Zombie is born!" << std::endl;
};

Zombie::Zombie(std::string	name){
	this->name = name;
	std::cout << this->name << " is born!" << std::endl;
};

Zombie::~Zombie(){
	std::cout << this->name << " is dead!" << std::endl;
};

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

void	Zombie::setName(std::string name){
	this->name = name;
};