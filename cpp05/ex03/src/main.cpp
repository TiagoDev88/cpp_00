#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void letsDoItWith(const std::string& form, const std::string& target, const Bureaucrat& bure)
{
    AForm* rrf;
    Intern intern;
    try
    {
        rrf = intern.makeForm(form, target);
        std::cout << *rrf << std::endl;
        bure.signForm(*rrf);
        bure.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


int main()
{
    try
    {
        std::cout << "\n------- With Boss Bureaucrat -------" << std::endl;
        Bureaucrat boss("Big Boss", 1);
        letsDoItWith("presidential pardon", "putin",boss);
        letsDoItWith("robotomy request", "botttt", boss);
        letsDoItWith("shrubbery creation", "42school", boss);
        letsDoItWith("invalid form", "Social Security", boss);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION BOSS: " << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat slave("slave", 120);
        std::cout << "\n------- With Slave Bureaucrat -------" << std::endl;
        letsDoItWith("presidential pardon", "putin", slave);
        letsDoItWith("robotomy request", "botttt", slave);
        letsDoItWith("shrubbery creation", "42school", slave);
        letsDoItWith("invalid form", "Social Security", slave);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION SLAVE: " << e.what() << '\n';
    }
    
    try
    {
        std::cout << "\n------- With Outform Bureaucrat -------" << std::endl;
        Bureaucrat outform("outform", 200);
        letsDoItWith("presidential pardon", "putin", outform);
        letsDoItWith("robotomy request", "botttt", outform);
        letsDoItWith("shrubbery creation", "42school", outform);
        letsDoItWith("invalid form", "Social Security", outform);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION OUTFORM: " << e.what() << '\n';
    }

    return 0;
}

