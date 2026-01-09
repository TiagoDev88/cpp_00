#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void letsDoItWithBoss(const std::string& form, const std::string& target)
{
    AForm* rrf;
    Intern intern;
    try
    {
        rrf = intern.makeForm(form, target);
        Bureaucrat boss("Big Boss", 1);
        rrf->beSigned(boss);
        rrf->execute(boss);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void letsDoItWithSlave(const std::string& form, const std::string& target)
{
    AForm* rrf;
    Intern intern;
    try
    {
        rrf = intern.makeForm(form, target);
        Bureaucrat slave("Slave", 14);
        rrf->beSigned(slave);
        rrf->execute(slave);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    std::cout << "\n------- With Boss Bureaucrat -------" << std::endl;
    letsDoItWithBoss("presidential pardon", "putin");
    letsDoItWithBoss("robotomy request", "botttt");
    letsDoItWithBoss("shrubbery creation", "42school");
    letsDoItWithBoss("invalid form", "Social Security");

    std::cout << "\n------- With Slave Bureaucrat -------" << std::endl;
    letsDoItWithSlave("presidential pardon", "putin");
    // letsDoItWithSlave("robotomy request", "botttt");
    // letsDoItWithSlave("shrubbery creation", "42school");
    // letsDoItWithSlave("invalid form", "Social Security");

    return 0;
}

