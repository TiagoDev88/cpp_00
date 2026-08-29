
#include "../inc/ScalarConverter.hpp"

// static_cast just converting between numbers
// (char, int, float, double) types that are similar to each other.
int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: ./convert\"test\"" << std::endl;
        return -1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
