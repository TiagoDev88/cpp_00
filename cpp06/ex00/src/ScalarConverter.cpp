

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
  if (str == "+inf" || str == "-inf" || str == "inf" || str == "+inff" || str == "-inff" || str == "inff" || str == "nan" || str == "nanf")
    return SPECIAL;
  
  size_t dot = str.find(".");
  size_t f = str.find("f");

  if (dot == std::string::npos || len == 1 || (len == 3 && str[0] == '\'' && str[2] == '\''))
  {
    if ((len == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) || (len == 3 && str[0] == '\'' && str[2] == '\''))
      return CHAR;
    else
    {
      for (size_t i = 0; i < len; i++)
      {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
          i++;
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
          return INVALID;
      }
      return INT;
    }
  }
  
  if (f != std::string::npos && dot != std::string::npos)
  {
    for(size_t i = 0; i < (len - 1); i++)
    {
      if (i == 0 && std::isdigit(static_cast<unsigned char>(str[i + 1])) && (str[i] == '-' || str[i] == '+'))
          i++;
      if (i != dot)
      {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
          return INVALID;
      }
    }
    if (str[f + 1] == '\0' && (dot + 1) != f)
      return FLOAT;
    else
      return INVALID;
  }

  if (f == std::string::npos && dot != std::string::npos)
  {
    for (size_t i = 0; i < len; i++)
    {
      if (i == 0 && std::isdigit(static_cast<unsigned char>(str[i + 1])) && (str[i] == '-' || str[i] == '+'))
        i++;
      if (i != dot)
      {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
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

static void printInt(const std::string &str)
{
  double c = std::strtod(str.c_str(), NULL);

  if(c < 0 || c > 127)
    std::cout << "char: impossible" << std::endl;
  else if(std::isprint(static_cast<int>(c)))
    std::cout << "char: '" << static_cast<unsigned char>(c) << "'" <<  std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;;
  if (c >= static_cast<double>(std::numeric_limits<int>::min()) && c <= static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << "int: " << static_cast<int>(c) << std::endl;
  else
    std::cout << "int: impossible\n";

  std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << c << std::endl;
}

static void printFloat(const std::string &str)
{
  float c = std::strtof(str.c_str(), NULL);

  if(c < 0 || c > 127)
    std::cout << "char: impossible" << std::endl;
  else if(std::isprint(static_cast<int>(c)))
    std::cout << "char: '" << static_cast<unsigned char>(c) << "'" <<  std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;;

  if (c >= static_cast<double>(std::numeric_limits<int>::min()) && c <= static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << "int: " << static_cast<int>(c) << std::endl;
  else
    std::cout << "int: impossible\n";

  if (c == std::floor(c))
    std::cout << "float: " << std::fixed << std::setprecision(1) <<  c << "f" << std::endl;
  else
    std::cout << "float: " <<  std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << c << "f" << std::endl;

  double d = static_cast<double>(c);
  if (d == std::floor(d))
    std::cout << "double: " << std::fixed << std::setprecision(1) <<  d << std::endl;
  else
    std::cout << "double: " << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << d << std::endl;
}

static void printDouble(const std::string &str)
{
  double c = std::strtod(str.c_str(), NULL);

  if(c < 0 || c > 127)
    std::cout << "char: impossible" << std::endl;
  else if(std::isprint(static_cast<int>(c)))
    std::cout << "char: '" << static_cast<unsigned char>(c) << "'" <<  std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;;

  if (c >= static_cast<double>(std::numeric_limits<int>::min()) && c <= static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << "int: " << static_cast<int>(c) << std::endl;
  else
    std::cout << "int: impossible\n";

  float f = static_cast<float>(c);
  if (f == std::floor(f))
    std::cout << "float: " << std::fixed << std::setprecision(1) <<  f << "f" << std::endl;
  else
    std::cout << "float: " <<  std::fixed << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;

  if (c == std::floor(c))
    std::cout << "double: " << std::fixed << std::setprecision(1) <<  c << std::endl;
  else
    std::cout << "double: " << std::fixed << std::setprecision(std::numeric_limits<double>::digits10) << c << std::endl;
}

static void printSpecial(const std::string &str)
{
  double val = std::strtod(str.c_str(), NULL);

  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << val << "f" << std::endl;
  std::cout << "double: " << val << std::endl;
}

// the float its like 6/7 precision and double is 15/17
void ScalarConverter::convert(const std::string &str)
{
  if (str.empty())
  {
    printInvalid();
    return;
  }
  std::string s = str;
  size_t len = str.length();
  bool withQuote = (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
  
  if (s.length() != 1 && !withQuote)
  {
    for (size_t i = 0; i < len; i++)
      s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
  }

  int type = getType(s, len);
  switch (type)
  {
    case SPECIAL:
      printSpecial(s);
      break;
    case CHAR:
      printChar(s, len);
      break;
    case INT:
      printInt(s);
      break;
    case FLOAT:
      printFloat(s);
      break;
    case DOUBLE:
      printDouble(s);
      break;
    default:
      printInvalid();
      break;
  }
}
