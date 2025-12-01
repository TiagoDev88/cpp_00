#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
    const Fixed _x;
    const Fixed _y;

    public:
    Point();
    Point(const Point& other);
    Point(const float x, const float y);
    ~Point();
    Point& operator=(const Point& other);

    Fixed getX(void) const;
    Fixed getY(void) const;

};

#endif