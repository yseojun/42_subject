#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed	&operator=(const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

};

#endif