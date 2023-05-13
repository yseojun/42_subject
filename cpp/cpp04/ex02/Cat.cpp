#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): A_Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	this->brain->ideas[0] = "Chewl! Chewl!";
};

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
};

Cat::Cat(const Cat &copy){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
};

Cat	&Cat::operator=(const Cat &copy){
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		std::copy(copy.brain, copy.brain + 100, this->brain);
	}
	return (*this);
};

void	Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
};

std::string Cat::getIdea(int i) const{
	return (this->brain->ideas[i]);
};