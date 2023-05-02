#include "Contact.hpp"

Contact::Contact( void ) {
	std::cout << "Contact constructor called" << std::endl;
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::~Contact( void ) {
	return ;
}

void	Contact::add( void ) {
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);

	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
}

void	Contact::print_all(void){
	print_each(first_name);
	std::cout << "|";
	print_each(last_name);
	std::cout << "|";
	print_each(nickname);
	std::cout << std::endl;
}

void	Contact::print_each( std::string str ) {
	for (int idx = 0; idx < 10; idx++)
	{
		if (idx == 9 && str.length() > 10)
			std::cout << ".";
		else if (idx < str.length())
			std::cout << str[idx];
		else
			std::cout << " ";
	}
}

void	Contact::print_index(void){
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl;
}