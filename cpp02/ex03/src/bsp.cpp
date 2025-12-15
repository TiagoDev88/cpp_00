
#include "Point.hpp"
#include "Fixed.hpp"

// Area = | x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2) |
static Fixed area(const Point a, const Point b, const Point c)
{
    Fixed areaA = a.getX() * (b.getY() - c.getY());
    Fixed areaB = b.getX() * (c.getY() - a.getY());
    Fixed areaC = c.getX() * (a.getY() - b.getY());
    Fixed total(areaA + areaB + areaC);

    if (total < Fixed(0))
        total = total * Fixed(-1);
    return total;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);

    if (areaABC == Fixed(0))
        return false;

    Fixed areaABP = area(a, b, point);
    Fixed areaBCP = area(b, c, point);
    Fixed areaCAP = area(c, a, point);

    if (areaABP == Fixed(0) || areaCAP == Fixed(0) || areaBCP == Fixed(0))
        return false;
    
    if ((areaABP + areaCAP + areaBCP) != areaABC)
        return false;

    return true;
}