#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice parametric constructor called" << std::endl;
};

Ice::Ice(Ice const & src) : AMateria(src){
	std::cout << "Ice copy constructor called" << std::endl;
};

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
};

Ice	&Ice::operator=(Ice const & rhs){
	std::cout << "Ice assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
};

AMateria* Ice::clone() const{
	return new Ice();
};

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at "
			<< target.getName() << " *" << std::endl;
};