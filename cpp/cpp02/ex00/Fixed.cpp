#include "Fixed.hpp"

Fixed::Fixed(void): fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &src){
	std::cout << "Copy constructor called" << std::endl;
};

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = rhs.getRawBits();
	return (*this);
};

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
};

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
};