#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	Phonebook	phonebook;
	int			count;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::string	command;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			phonebook.add(count % 8);
			count++;
		}
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command" << std::endl;
	}
}