#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): A_Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->brain->ideas[0] = "Bone! Bone!";
};

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
};

Dog::Dog(const Dog &copy){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
};

Dog	&Dog::operator=(const Dog &copy){
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		std::copy(copy.brain, copy.brain + 100, this->brain);
	}
	return (*this);
};

void	Dog::makeSound() const{
	std::cout << "Woof!" << std::endl;
};

std::string	Dog::getIdea(int i) const{
	return (this->brain->ideas[i]);
};

void	Dog::setIdea(int i, std::string idea){
	this->brain->ideas[i] = idea;
};