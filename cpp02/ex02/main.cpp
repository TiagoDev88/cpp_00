

// #include "Fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }




#include <iostream>
#include "Fixed.hpp"

int main() {
    std::cout << "\n=== BASIC CONSTRUCTION ===\n";
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "d = " << d << "\n";

    std::cout << "\n=== ASSIGNMENT ===\n";
    a = Fixed(5.5f);
    std::cout << "a = " << a << "\n";

    std::cout << "\n=== COMPARISON OPERATORS ===\n";
    std::cout << "b > c: " << (b > c) << "\n";
    std::cout << "b < c: " << (b < c) << "\n";
    std::cout << "b >= d: " << (b >= d) << "\n";
    std::cout << "b == d: " << (b == d) << "\n";
    std::cout << "c != d: " << (c != d) << "\n";

    std::cout << "\n=== ARITHMETIC OPERATORS ===\n";
    Fixed x(5.05f);
    Fixed y(2);

    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";
    std::cout << "x / y = " << (x / y) << "\n";

    std::cout << "\n=== INCREMENT/DECREMENT ===\n";
    Fixed inc;

    std::cout << "inc = " << inc << "\n";
    std::cout << "++inc = " << ++inc << "\n";
    std::cout << "inc++ = " << inc++ << "\n";
    std::cout << "inc = " << inc << "\n";

    std::cout << "\n=== MIN/MAX ===\n";
    std::cout << "min(x, y) = " << Fixed::min(x, y) << "\n";
    std::cout << "max(x, y) = " << Fixed::max(x, y) << "\n";

    return 0;
}

