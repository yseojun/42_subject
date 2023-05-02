#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );

	void	add( int index );
	void	search( void );

private:

	Contact	contacts[8];

};

#endif