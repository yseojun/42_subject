#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type): type(type){
	std::cout << "WrongAnimal type constructor called" << std::endl;
};

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
};

std::string	WrongAnimal::getType() const{
	return (this->type);
};

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound!" << std::endl;
};