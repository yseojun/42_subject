#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "---------Debug---------" << std::endl;
	harl.complain("debug");
	std::cout << std::endl << "---------Info---------" << std::endl << std::endl;
	harl.complain("info");
	std::cout << std::endl << "---------Warning---------" << std::endl << std::endl;
	harl.complain("warning");
	std::cout << std::endl << "---------Error---------" << std::endl << std::endl;
	harl.complain("error");
	std::cout << std::endl << "---------Invalid---------" << std::endl << std::endl;
	harl.complain("fatal");
	std::cout << std::endl;

	return (0);
}