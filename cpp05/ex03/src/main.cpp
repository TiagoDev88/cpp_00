#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    // Bureaucrat bigboss("BigBoss", 1);
    // Bureaucrat slave("Slave", 140);

    // ShrubberyCreationForm shrub("school 42");
    // RobotomyRequestForm robo("Kiko");
    // PresidentialPardonForm pardon("Donald Trump");

    // try {
    //     shrub.execute(bigboss);
    // }
    // catch (std::exception& e) {
    //     std::cerr << "Error" << e.what() << std::endl;
    // }

    // std::cout << "\n--- SIGN TESTS ---\n";
    // slave.signForm(shrub);
    // slave.signForm(robo);
    // slave.signForm(pardon);
    // bigboss.signForm(shrub);
    // bigboss.signForm(robo);
    // bigboss.signForm(pardon);

    // std::cout << "\n--- EXECUTE TESTS ---\n";
    // slave.executeForm(shrub);   
    // slave.executeForm(robo);
    // slave.executeForm(pardon); 
    // bigboss.executeForm(shrub);
    // bigboss.executeForm(robo);     // its 50% robotomized, so I use 3 times to see.
    // bigboss.executeForm(robo);     
    // bigboss.executeForm(robo);     
    // bigboss.executeForm(pardon);

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    return 0;
}
