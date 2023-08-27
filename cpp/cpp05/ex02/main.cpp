#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		ShrubberyCreationForm	a("home");
		RobotomyRequestForm		b("away");
		PresidentialPardonForm	c("asd");
		Bureaucrat me("seojyang", 10);
		me.signForm(a);
		me.executeForm(a);
		me.signForm(b);
		me.executeForm(b);
		me.signForm(c);
		me.executeForm(c);
	}

	{
		ShrubberyCreationForm	a("home");
		RobotomyRequestForm		b("away");
		PresidentialPardonForm	c("asd");
		Bureaucrat me("seojyang", 1);
		me.signForm(a);
		me.executeForm(a);
		me.signForm(b);
		me.executeForm(b);
		me.signForm(c);
		me.executeForm(c);
	}
}
