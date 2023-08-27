#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidentialpardon", false, 25, 5), target("default"){
	std::cout << "Presidentialpardonform default constructor called" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidentialpardonform default destructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidentialpardon", false, 25, 5), target(target){
	std::cout << "Presidentialpardonform paramatic constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src), target(src.target){
	std::cout << "Presidentialpardonform copy constructor called" << std::endl;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs){
	std::cout << "Presidentialpardonform assignment opertor called" << std::endl;
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return *this;
};

void	PresidentialPardonForm::specialwork() const{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
};
