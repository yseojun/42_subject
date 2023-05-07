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

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	x;
		Fixed const	y;
};

#endif