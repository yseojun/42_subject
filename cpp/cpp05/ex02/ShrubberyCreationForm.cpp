#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm ("Shrubbery", false, 145, 137), target("default"){
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm ("Shrubbery", false, 145, 137), target(target){
	std::cout << "ShrubberyCreationForm paramatic constructor called" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: AForm(src), target(src.target){
	std::cout << "ShrubberyCreationForm copy instructor called" << std::endl;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs){
	std::cout << "Shrubberycreationform assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->isSigned = rhs.getIsSigned();
	}
	return *this;
};

void	ShrubberyCreationForm::specialwork() const{
	std::string	file_name = target + "_shrubbery";
	std::ofstream file(file_name.c_str());
	if (!file.is_open())
	{
		throw "failed to create file!";
	}

	file <<
	"		ccee88oo\n\
	C8O8O8Q8PoOb o8oo\n\
	dOB69QO8PdUOpugoO9bD\n\
	CgggbU8OU qOp qOdoUOdcb\n\
		6OuU  /p u gcoUodpP\n\
		\\\\//  /douUP\n\
			\\\\////\n\
			|||/\n\
			|||\\/\n\
			|||||\n\
	.....//||||\\....\n";
	
	file.close();
};
