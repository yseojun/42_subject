#include "Intern.hpp"

AForm	*Intern::makeForm(std::string formName, std::string target){
	AForm	*form = nullptr;

	std::string	types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*(*classTypes[3])(std::string const &)
		= { &PresidentialPardonForm::createInstance,
			&RobotomyRequestForm::createInstance,
			&ShrubberyCreationForm::createInstance };
	for (int i = 0; i < 3; i++)
	{
		if (formName == types[i])
		{
			form = classTypes[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break ;
		}
	}
	return form;
};
