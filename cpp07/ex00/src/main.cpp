
#include "../inc/whatever.hpp"
#include <string>
#include <iostream>

// use :: because for dont use ADL (Argument Dependent Lookup)
// and use my template
int main (void)
{
    int a = 10;
    int b = 5;

    std::cout << "Normal: a-> " << a << " " << "b-> " << b << std::endl;

    std::cout << "min -> " << ::min(a, b) << std::endl;
    std::cout << "max -> " << ::max(a, b) << std::endl;
    ::swap(a, b);
    std::cout << "With swap: a-> " << a << " " << "b-> " << b << std::endl;

    ::swap(a, b);
    std::cout << "Normal again: a-> " << a << " " << "b-> " << b << std::endl;

    std::string c = "test1";
    std::string d = "test2";

    std::cout << "Normal: c-> " << c << " " << "d-> " << d << std::endl;

    std::cout << "min -> " << ::min(c, d) << std::endl;
    std::cout << "max -> " << ::max(c, d) << std::endl;
    ::swap(c, d);
    std::cout << "With swap: c-> " << c << " " << "d-> " << d << std::endl;

    ::swap(c, d);
    std::cout << "Normal again: c-> " << c << " " << "d-> " << d << std::endl;

    return 0;
}
