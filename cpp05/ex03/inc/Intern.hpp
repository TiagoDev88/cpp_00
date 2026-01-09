#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    class FormNotFoundException : public std::exception
    {
        public:
        const char* what() const throw();
    };

    AForm* makeForm(const std::string& name_form, const std::string& target) const;
};

#endif