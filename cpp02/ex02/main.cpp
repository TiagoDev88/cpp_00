
#include <iostream>
#include "Fixed.hpp"

int main() 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "SUBJECT TESTS:\n";
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\n=== BASIC CONSTRUCTION ===\n";
    Fixed c;
    Fixed d(10);
    Fixed e(42.42f);
    Fixed f(d);

    std::cout << "c = " << c << "\n";
    std::cout << "d = " << d << "\n";
    std::cout << "e = " << e << "\n";
    std::cout << "f = " << f << "\n";

    std::cout << "\n=== ASSIGNMENT ===\n";
    c = Fixed(5.5f);
    std::cout << "c = " << c << "\n";

    std::cout << "\n=== COMPARISON OPERATORS ===\n";
    std::cout << "d > c: " << (d > c) << "\n";
    std::cout << "d < c: " << (d < c) << "\n";
    std::cout << "d >= d: " << (d >= d) << "\n";
    std::cout << "d == d: " << (d == d) << "\n";
    std::cout << "c != d: " << (c != d) << "\n";
    std::cout << "c <= d: " << (c <= d) << "\n";
    std::cout << "c >= d: " << (c >= d) << "\n";
    std::cout << "c == c: " << (c == c) << "\n";
    std::cout << "c != c: " << (c != c) << "\n";

    std::cout << "\n=== ARITHMETIC OPERATORS ===\n";
    Fixed x(5.05f);
    Fixed y(2);

    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";
    std::cout << "x / y = " << (x / y) << "\n";
    std::cout << "e / y = " << (e / y) << "\n";
    std::cout << "e * y = " << (e * y) << "\n";

    std::cout << "\n=== INCREMENT/DECREMENT ===\n";
    Fixed inc;

    std::cout << "inc = " << inc << "\n";
    std::cout << "++inc = " << ++inc << "\n";
    std::cout << "inc++ = " << inc++ << "\n";
    std::cout << "inc = " << inc << "\n";
    std::cout << "--inc = " << --inc << "\n";
    std::cout << "inc-- = " << inc-- << "\n";
    std::cout << "inc = " << inc << "\n";
    

    std::cout << "\n=== MIN/MAX ===\n";
    std::cout << "min(x, y) = " << Fixed::min(x, y) << "\n";
    std::cout << "max(x, y) = " << Fixed::max(x, y) << "\n";

    const Fixed cx(3.99f);
    const Fixed cy(4);
    std::cout << "min(cx, cy) = " << Fixed::min(cx, cy) << "\n";
    std::cout << "max(cx, cy) = " << Fixed::max(cx, cy) << "\n";

    return 0;
}

