

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
  (void)other;
   return (*this); 
}

ScalarConverter::~ScalarConverter() {}

int getType(const std::string &str, size_t len)
{
  if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
    return SPECIAL;
  
  size_t dot = str.find(".");
  size_t f = str.find("f");

  //todo talvez aqui, verificar se por exemplo o '.' conta como char ou nao.
  // caso conte, talvez no if, verifico se e superior a 1 caracter, para interpretar sem ser char.
  if (dot == std::string::npos)
  {
    // aqui vai ser int, char
    if ((len == 1 && !std::isdigit(str[0])) || (len == 3 && str[0] == '\'' && str[2] == '\''))
      return CHAR;
    else
      return INT;
  }
  
  if (f != std::string::npos && dot != std::string::npos)
  {
    // aqui vai ser o float

  }

  if (f == std::string::npos && dot != std::string::npos)
  {
    // aqui vai ser o double
  }
  return INVALID;
}

void ScalarConverter::convert(const std::string &str)
{
  size_t len = str.length();
  int type = getType(str, len);
  switch (type)
  {
    case SPECIAL:
      // printSpecial
      break;
    case CHAR:
      //printChar
      break;
    case INT:
      //printInt
      break;
    case FLOAT:
      //printFloat
      break;
    case DOUBLE:
      //printDouble
      break;
    default:
      //printInvalid
      break;
  }

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