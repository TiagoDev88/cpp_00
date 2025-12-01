#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <iomanip> // i m use to std::setw
#include <string>
#include <cstdlib> // i m use to std::atoi

int is_alpha(std::string s);
int is_number(std::string s);
int is_only_space(std::string s);
std::string clear_line(std::string s);

#endif