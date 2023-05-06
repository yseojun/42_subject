#include <iostream>

int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*pointer = &brain;
	std::string	&address = brain;
	
	std::cout << "address of string : " << &brain << std::endl
			<< "address of strPTR : " << &pointer << std::endl
			<< "address of strREF : " << &address << std::endl;

	std::cout << "value of string : " << brain << std::endl
			<< "value of strPTR : " << *pointer << std::endl
			<< "value of strREF : " << address << std::endl;
}