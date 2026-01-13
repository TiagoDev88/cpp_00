
#include "../inc/ScalarConverter.hpp"

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: ./ex00 \"test\"" << std::endl;
        return -1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}