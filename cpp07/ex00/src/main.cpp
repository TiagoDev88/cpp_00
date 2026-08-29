
#include "../inc/whatever.hpp"

int main (void)
{
    int a = 10;
    int b = 5;

    std::cout << "Normal: a-> " << a << " " << "b-> " << b << std::endl;

    std::cout << "min -> " << ::min(a, b) << std::endl;
    std::cout << "max -> " << ::max(a, b) << std::endl;
    swap(a, b);
    std::cout << "With swap: a-> " << a << " " << "b-> " << b << std::endl;

    swap(a, b);
    std::cout << "Normal again: a-> " << a << " " << "b-> " << b << std::endl;

    return 0;
}
