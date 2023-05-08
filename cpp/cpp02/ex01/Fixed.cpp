#include "Fixed.hpp"

Fixed::Fixed(void)
	:fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int value)
	:fixedPointValue(value << fractionalBits){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float value)
	:fixedPointValue(roundf(value * (1 << fractionalBits))){
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &src){
	this->fixedPointValue = src.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
};

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &rhs){
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
};

int	Fixed::getRawBits(void) const{
	return fixedPointValue;
};

void	Fixed::setRawBits(int const raw){
	fixedPointValue = raw;
};

float	Fixed::toFloat(void) const{
	return (float)fixedPointValue / (1 << fractionalBits);
};

int		Fixed::toInt(void) const{
	return fixedPointValue >> fractionalBits;
};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed){
	os << fixed.toFloat();
	return os;
};
