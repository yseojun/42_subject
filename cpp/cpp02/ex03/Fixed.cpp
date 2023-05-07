#include "Fixed.hpp"

Fixed::Fixed(void)
	:fixedPointValue(0){
};

Fixed::Fixed(const int value)
	:fixedPointValue(value << fractionalBits){
};

Fixed::Fixed(const float value)
	:fixedPointValue(value * (1 << fractionalBits)){
};

Fixed::Fixed(const Fixed &src){
	this->fixedPointValue = src.getRawBits();
};

Fixed::~Fixed(void){
};

Fixed	&Fixed::operator=(const Fixed &rhs){
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
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

bool Fixed::operator>(const Fixed &rhs) const{ 
	return fixedPointValue > rhs.getRawBits(); 
};

bool Fixed::operator<(const Fixed &rhs) const{
	return fixedPointValue < rhs.getRawBits();
};

bool Fixed::operator>=(const Fixed &rhs) const{
	return fixedPointValue >= rhs.getRawBits();
};

bool Fixed::operator<=(const Fixed &rhs) const{
	return fixedPointValue <= rhs.getRawBits();
};

bool Fixed::operator==(const Fixed &rhs) const{
	return fixedPointValue == rhs.getRawBits();
};

bool Fixed::operator!=(const Fixed &rhs) const{
	return fixedPointValue != rhs.getRawBits();
};

Fixed	Fixed::operator+(const Fixed &rhs){
	return Fixed(toFloat() + rhs.toFloat());
};

Fixed	Fixed::operator-(const Fixed &rhs){
	return Fixed(toFloat() - rhs.toFloat());
};

Fixed	Fixed::operator*(const Fixed &rhs){
	return Fixed(toFloat() * rhs.toFloat());
};

Fixed	Fixed::operator/(const Fixed &rhs){
	return Fixed(toFloat() / rhs.toFloat());
};

Fixed	&Fixed::operator++(){
	fixedPointValue++;
	return (*this);
};

Fixed	Fixed::operator++(int){
	Fixed tmp(*this);
	operator++();
	return (tmp);
};

Fixed	&Fixed::operator--(){
	fixedPointValue--;
	return (*this);
};

Fixed	Fixed::operator--(int){
	Fixed tmp(*this);
	operator--();
	return (tmp);
};

Fixed& Fixed::min(Fixed &a, Fixed &b){
	return (a < b ? a : b);
};

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
	return (a < b ? a : b);
};

Fixed& Fixed::max(Fixed &a, Fixed &b){
	return (a > b ? a : b);
};

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	return (a > b ? a : b);
};