#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Bureaucrat me("seojyang", 1);
		AForm *rob;
		AForm *shr;
		AForm *pre;
		Intern someone;

		rob = someone.makeForm("robotomy request", "last");
		shr = someone.makeForm("shrubbery creation", "test");
		pre = someone.makeForm("presidential pardon", "great!");

		me.signForm(*rob);
		me.executeForm(*rob);
		me.signForm(*shr);
		me.executeForm(*shr);
		me.signForm(*pre);
		me.executeForm(*pre);

		delete rob;
		delete shr;
		delete pre;
	}
}
