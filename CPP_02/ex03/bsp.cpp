
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab = (a.getY() - b.getY());
    std::cout << "ab: " << ab << std::endl;

    Fixed ac = (a.getY() - c.getY());
    std::cout << "ac: " << ac << std::endl;

    Fixed bc = (b.getY() - c.getY());
    std::cout << "ab: " << bc << std::endl;

    Fixed pointX = point.getX(); 
    std::cout << "POINTx: " << pointX << std::endl;

    return true;
}