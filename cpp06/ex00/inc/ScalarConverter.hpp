#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

    public:
    ~ScalarConverter();
    static void convert(const std::string &str);
};

#endif