#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << "AMateria parametric constructor called" << std::endl;
};

AMateria::AMateria(AMateria const & src){
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
};

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
};

std::string const & AMateria::getType() const{
	return this->type;
};