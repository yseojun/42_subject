#include "Point.hpp"

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
    if (this != &rhs)
	{
		const_cast<Fixed&>(x) = rhs.x;
		const_cast<Fixed&>(y) = rhs.y;
	}
    return *this;
}

Fixed	Point::getX(void) const{
	return x;
};

Fixed	Point::getY(void) const{
	return y;
};