

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
  (void)other;
   return (*this); 
}

ScalarConverter::~ScalarConverter() {}

int detectType(const std::string& str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        std::cout << "Detected type: char" << std::endl;
        return 0;
    }
    if (str.find('.') == std::string::npos && str.find('f') == std::string::npos)
    {
        try
        {
            std::stoi(str);
            std::cout << "Detected type: int" << std::endl;
            return 1;
        }
        catch (const std::exception&)
        {
            // Not an int
        }
    }
    if (str.find('f') != std::string::npos)
    {
        try
        {
            std::stof(str);
            std::cout << "Detected type: float" << std::endl;
            return 2;
        }
        catch (const std::exception&)
        {
            // Not a float
        }
    }
    return -1;
}

void ScalarConverter::convert(const std::string str)
{
  if(str.empty())
  {
      std::cerr << "Error: Empty string provided." << std::endl;
      return;
  }
  switch (detectType(str))
  {
  case 0:
    std::cout << "Detected type: char" << std::endl;
    break;
  case 1:
    std::cout << "Detected type: int" << std::endl;
    break;
  case 2:
    std::cout << "Detected type: float" << std::endl;
    break;
  case 3:
    std::cout << "Detected type: double" << std::endl;
    break;
  default:
    std::cerr << "Error: Unknown type." << std::endl;
    break;
  }
}

/*
  • char
  • int
  • float
  • double
*/