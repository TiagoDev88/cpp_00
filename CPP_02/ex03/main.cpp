

#include "Point.hpp"
#include "Fixed.hpp"

int main( void ) {
    Point a( 0.0f, 0.0f );
    Point b( 10.0f, 30.0f );
    Point c( 20.0f, 0.0f );

    Point p1( 10.0f, 15.0f );
    Point p2( 30.0f, 15.0f );

    if ( bsp( a, b, c, p1 ) )
        std::cout << "Point p1 is inside the triangle ABC" << std::endl;
    else
        std::cout << "Point p1 is outside the triangle ABC" << std::endl;

    if ( bsp( a, b, c, p2 ) )
        std::cout << "Point p2 is inside the triangle ABC" << std::endl;
    else
        std::cout << "Point p2 is outside the triangle ABC" << std::endl;

    return 0;
}