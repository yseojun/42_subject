#ifndef	POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const int x, const int y);
		Point(const float x, const float y);
		Point(const Point &src);
		~Point(void);
		Point	&operator=(const Point &rhs);

		Fixed	const getX(void) const;
		Fixed	const getY(void) const;
		void	setX(const Fixed x);
		void	setY(const Fixed y);
		
	private:
		Fixed const	x;
		Fixed const	y;
};

#endif