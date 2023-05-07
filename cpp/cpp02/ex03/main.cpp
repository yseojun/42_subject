#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	{
		Point point(2, 2);
		if (bsp(a, b, c, point) == 1)
			std::cout << "Point is inside the triangle" << std::endl;
		else
			std::cout << "Point is outside the triangle" << std::endl;
	}
	{
		Point point(3, 3);
		
		if (bsp(a, b, c, point) == 1)
			std::cout << "Point is inside the triangle" << std::endl;
		else
			std::cout << "Point is outside the triangle" << std::endl;
	}
	return (0);
}