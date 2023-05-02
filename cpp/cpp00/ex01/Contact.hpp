#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

public:

	Contact( void );
	~Contact( void );

	void	add( void );
	void	print_all( void );
	void	print_each( std::string str );
	void	print_index( void );

private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

};

#endif