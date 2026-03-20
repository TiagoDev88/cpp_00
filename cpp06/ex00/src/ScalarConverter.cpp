

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
  (void)other;
   return (*this); 
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string &str)
{
  int len = str.length();
  std::cout << len << std::endl;
  
  if(str.empty())
  {
      std::cerr << "Error: Empty string provided." << std::endl;
      return;
  }
  //verificar se e char
  if (len == 1 && !std::isdigit(str[0]))
  {
    std::cout << "char: " << str << std::endl;
    std::cout << "int: " << str << std::endl;
    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str << std::endl;

    return ;
  }

}

/*
  • char
  • int
  • float
  • double
*/