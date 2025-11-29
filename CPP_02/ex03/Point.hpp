
#include "Fixed.hpp"

class Point
{
    private:
    Fixed _x;
    Fixed _y;

    public:
    Point();
    Point(const Point& other);
    Point(const float x, const float y);
    ~Point();
    Point& operator=(const Point& other);

};