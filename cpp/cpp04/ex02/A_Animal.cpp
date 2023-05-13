#include "A_Animal.hpp"

A_Animal::A_Animal(): type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
};

A_Animal::A_Animal(std::string type): type(type){
	std::cout << "Animal type constructor called" << std::endl;
};

A_Animal::~A_Animal(){
	std::cout << "Animal destructor called" << std::endl;
};

A_Animal::A_Animal(const A_Animal &copy){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
};

A_Animal &A_Animal::operator=(const A_Animal &copy){
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
};

std::string	A_Animal::getType() const{
	return (this->type);
};

// void	A_Animal::makeSound() const{
// 	std::cout << "Animal sound!" << std::endl;
// };

// std::string A_Animal::getIdea(int i) const{
// 	i = 0;
// 	return ("...");
// };