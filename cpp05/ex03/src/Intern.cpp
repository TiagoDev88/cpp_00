


#include "../inc/Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) {};

// Intern& Intern::operator=(const Intern& other) {};

Intern::~Intern(){};

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

    try
    {
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
            std::cerr << "form name does not exist" << std::endl;
            break;
        }
        std::cout << "Inter creates " << form->getName() << std::endl;
        return form;
    }
    catch(const std::exception& e)
    {
        std::cerr << "TESTE DO INTERN" << e.what() << '\n';
    }
};
