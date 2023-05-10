#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat"){
	std::cout << "WrongCat default constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &copy){
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
};

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat	&WrongCat::operator=(const WrongCat &copy){
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
};

void	WrongCat::makeSound() const{
	std::cout << "Meow!" << std::endl;
};