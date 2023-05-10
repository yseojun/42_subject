#include "Animal.hpp"

Animal::Animal(): type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
};

Animal::Animal(std::string type): type(type){
	std::cout << "Animal type constructor called" << std::endl;
};

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
};

Animal::Animal(const Animal &copy){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
};

Animal &Animal::operator=(const Animal &copy){
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
};

std::string	Animal::getType() const{
	return (this->type);
};

void	Animal::makeSound() const{
	std::cout << "Animal sound!" << std::endl;
};