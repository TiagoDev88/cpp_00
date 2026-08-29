#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <climits>
#include <limits>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <iomanip>

enum e_Type
{
    SPECIAL,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID = -1
};

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    public:
    static void convert(const std::string &str);
};

#endif