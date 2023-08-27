#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << '\n';
		Form first = Form("First", false, 150, 100);
		std::cout << first; 
		std::cout << '\n';
	}

	{
		std::cout << '\n';
		Bureaucrat seojyang = Bureaucrat("seojyang",10);
		Form second = Form("Second", false, 100, 100);
		Form third = Form("Third", false, 5, 5);
		std::cout << second;
		seojyang.signForm(second);
		std::cout << '\n';
		std::cout << third;
		seojyang.signForm(third);
	}

}
