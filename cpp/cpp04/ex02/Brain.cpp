#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
};

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
};

Brain::Brain(const Brain &copy){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
};

Brain	&Brain::operator=(const Brain &copy){
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
		std::copy(copy.ideas, copy.ideas + 100, ideas);
	return (*this);
};