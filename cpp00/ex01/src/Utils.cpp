
#include "Utils.hpp"

int is_alpha(std::string s)
{
	int i = 0;
	while (s[i])
	{
		if (!std::isalpha(s[i]) && !std::isspace(s[i]))
			return (0);
		i++;
	}
	return 1;
}

int is_number(std::string s)
{
	int i = 0;
	while (s[i])
	{
		if (!std::isdigit(s[i]) && !std::isspace(s[i]) && s[i] != '+')
			return (0);
		i++;
	}
	return 1;
}

std::string clear_line(std::string s)
{
	for (size_t i = 0; i < s.size();i++)
	{
		if (s[i] == '\t')
			s[i] = ' ';
	}
	return s;
}

int is_only_space(std::string s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ')
			return 0;
		i++;
	}
	return 1;
}