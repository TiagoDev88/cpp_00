


#include "../inc/Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) { *this = other; };

Intern& Intern::operator=(const Intern& other) 
{
    (void)other;
    return *this;
};

Intern::~Intern(){};

const char* Intern::FormNotFoundException::what() const throw()
{
    return "form name does not exist";
};


AForm* Intern::makeForm(const std::string& name_form, const std::string& target) const
{
    std::string check[3] = {"presidential pardon",
                            "robotomy request",
                            "shrubbery creation"};
    AForm* form = NULL;
    int num = -1;

    for (int i = 0; i < 3; i++)
    {
        if (name_form == check[i])
            num = i;
    }
    switch (num)
    {
        case 0:
            form = new PresidentialPardonForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            break;
        default:
            throw FormNotFoundException();
    }
    std::cout << "Inter creates " << form->getName()
                      << std::endl;
    return form;
};
