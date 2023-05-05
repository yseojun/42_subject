#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook( void ){
	return ;
}

Phonebook::~Phonebook( void ){
	return ;
}

void	Phonebook::add(int index){
	contacts[index].add();
	std::cout << "Contact added!" << std::endl;
}

void	Phonebook::search(void){
	std::cout << "index |first name|last  name|nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "  " << i << "   |";
		contacts[i].print_all();
	}
	std::cout << "Enter an index: ";
	std::string	index;
	std::getline(std::cin, index);
	if (index.length() == 1 && '0' <= index[0] && index[0] <= '7')
		contacts[index[0] - '0'].print_index();
	else
		std::cout << "Invalid index" << std::endl;
}