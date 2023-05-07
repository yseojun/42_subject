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

    Fixed tri = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (tri < 0)
        tri = tri * -1;

    Fixed t1 = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
    if (t1 < 0)
        t1 = t1 * -1;
    Fixed t2 = (x3 - x2) * (y - y2) - (y3 - y2) * (x - x2);
    if (t2 < 0)
        t2 = t2 * -1;
    Fixed t3 = (x1 - x3) * (y - y3) - (y1 - y3) * (x - x3);
    if (t3 < 0)
        t3 = t3 * -1;

    std::cout << "s: " << tri << " a1: " << t1 << " a2: " << t2 << " a3: " << t3 << std::endl;

    return tri == t1 + t2 + t3;
}
