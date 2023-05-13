#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure parametric constructor called" << std::endl;
};

Cure::Cure(Cure const & src) : AMateria(src){
	std::cout << "Cure copy constructor called" << std::endl;
};

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
};

Cure	&Cure::operator=(Cure const & rhs){
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
};

AMateria* Cure::clone() const{
	return new Cure();
};

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() 
			<< "'s wounds *" << std::endl;
};
