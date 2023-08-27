#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << '\n';
		Bureaucrat("high", 0);
		std::cout << '\n';
		Bureaucrat("Low", 151);
	}

	{
		std::cout << '\n';
		Bureaucrat hey = Bureaucrat("hey", 5);
		std::cout << hey++;
		std::cout << ++hey;
		std::cout << hey;
	}

	{
		std::cout << '\n';
		Bureaucrat top = Bureaucrat("top", 1);
		std::cout << top++;
		std::cout << ++top;
		std::cout << top;
	}

	{
		std::cout << '\n';
		Bureaucrat bottom = Bureaucrat("bottom", 150);
		std::cout << bottom--;
		std::cout << --bottom;
		std::cout << bottom;
	}
}
