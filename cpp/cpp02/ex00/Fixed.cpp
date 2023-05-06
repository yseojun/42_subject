#include "Fixed.hpp"

Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &src){
	std::cout << "Copy constructor called" << std::endl;
};

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &rhs){
	std::cout << "Assignation operator called" << std::endl;
	return (*this);
};

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (0);
};

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
};