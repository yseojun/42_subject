#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed x1 = a.getX();
    Fixed y1 = a.getY();
    Fixed x2 = b.getX();
    Fixed y2 = b.getY();
    Fixed x3 = c.getX();
    Fixed y3 = c.getY();
    Fixed x = point.getX();
    Fixed y = point.getY();

    Fixed tri = x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
    if (tri < 0)
        tri = tri * -1;

    Fixed t1 = x * y2 + x2 * y3 + x3 * y - x * y3 - x2 * y - x3 * y2;
    if (t1 < 0)
        t1 = t1 * -1;
    Fixed t2 = x * y1 + x1 * y3 + x3 * y - x * y3 - x1 * y - x3 * y1;
    if (t2 < 0)
        t2 = t2 * -1;
    Fixed t3 = x * y1 + x1 * y2 + x2 * y - x * y2 - x1 * y - x2 * y1;
    if (t3 < 0)
        t3 = t3 * -1;

    std::cout << "s: " << tri << " a1: " << t1 << " a2: " << t2 << " a3: " << t3 << std::endl;

    return tri == t1 + t2 + t3;
}
