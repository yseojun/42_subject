#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed	&operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		friend	std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

		bool	operator>(const Fixed &rhs) const;
    	bool	operator<(const Fixed &rhs) const;
    	bool	operator>=(const Fixed &rhs) const;
    	bool	operator<=(const Fixed &rhs) const;
    	bool	operator==(const Fixed &rhs) const;
    	bool	operator!=(const Fixed &rhs) const;

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static	Fixed& min(Fixed &a, Fixed &b);
		static	const Fixed& min(const Fixed &a, const Fixed &b);
    	static	Fixed& max(Fixed &a, Fixed &b);
    	static	const Fixed& max(const Fixed &a, const Fixed &b);

	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;

};

#endif