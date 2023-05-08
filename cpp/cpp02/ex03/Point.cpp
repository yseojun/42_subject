#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): x(0), y(0){
};

Point::Point(const int x, const int y): x(Fixed(x)), y(Fixed(y)){
};

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)){
};

Point::Point(const Point &src){
	*this = src;
};

Point::~Point(void){
};

Point& Point::operator=(const Point &rhs)
{
	this->~Point();

	new(this)	Point(rhs.x.toFloat(), rhs.y.toFloat());
	return (*this);
}

Fixed	const Point::getX(void) const{
	return x;
};

Fixed	const Point::getY(void) const{
	return y;
};
