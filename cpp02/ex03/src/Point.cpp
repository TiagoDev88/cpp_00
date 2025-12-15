

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point() {}

Point& Point::operator=(const Point& other)
{
    static_cast<void>(other);
    return *this;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}