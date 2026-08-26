

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
  (void)other;
   return (*this); 
}

ScalarConverter::~ScalarConverter() {}

static int getType(const std::string &str, size_t len)
{
  if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
    return SPECIAL;
  
  size_t dot = str.find(".");
  size_t f = str.find("f");

  //todo talvez aqui, verificar se por exemplo o '.' conta como char ou nao.
  // caso conte, talvez no if, verifico se e superior a 1 caracter, para interpretar sem ser char.
  if (dot == std::string::npos || len == 1)
  {
    // aqui vai ser int, char
    if ((len == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) || (len == 3 && str[0] == '\'' && str[2] == '\''))
      return CHAR;
    else
    {
      for (size_t i = 0; i < len; i++)
      {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
          i++;
        if (!std::isdigit(str[i]))
          return INVALID;
      }
      return INT;
    }
  }
  
  // aqui vai ser o float
  if (f != std::string::npos && dot != std::string::npos)
  {
    for(size_t i = 0; i < (len - 1); i++)
    {
      if (i != dot)
      {
        if (!std::isdigit(str[i]))
          return INVALID;
      }
    }
    if (str[f + 1] == '\0' && (dot + 1) != f)
      return FLOAT;
    else
      return INVALID;
  }

  // aqui vai ser o double
  if (f == std::string::npos && dot != std::string::npos)
  {
    for (size_t i = 0; i < len; i++)
    {
      if (i != dot)
      {
        if (!std::isdigit(str[i]))
          return INVALID;
      }
    }
    if (str[dot + 1] == '\0')
      return INVALID;
    else
      return DOUBLE;
  }
  return INVALID;
}

static void printChar(const std::string &str, size_t len)
{
  char c;
  if (len == 3)
    c = static_cast<unsigned char>(str[1]);
  else 
    c = static_cast<unsigned char>(str[0]);

  if (std::isprint(static_cast<int>(c)))
    std::cout << "char: " << "'" << c << "'" << std::endl;
  else
    std::cout << "char: " << "Non displayable" << std::endl;
  
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
  if (str.empty())
  {
    printInvalid();
    return;
  }
  size_t len = str.length();
  int type = getType(str, len);
  switch (type)
  {
    case SPECIAL:
      // printSpecial
      std::cout << "SPECIAL\n";
      break;
    case CHAR:
      //printChar
      printChar(str, len);
      break;
    case INT:
      //printInt
      std::cout << "INT\n";
      break;
    case FLOAT:
      //printFloat
      std::cout << "FLOAT\n";
      break;
    case DOUBLE:
      //printDouble
      std::cout << "DOUBLE\n";
      break;
    default:
      printInvalid();
      break;
  }
}
