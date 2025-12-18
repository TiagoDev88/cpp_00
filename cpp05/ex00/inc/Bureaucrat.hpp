#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat
{
    private:
    const std::string _name;
    int         _grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    void GradeTooHighException() const;
    void GradeTooLowException() const;

};
//TODO: talvez tirar o const do std::ostream& os, testar e logo vejo.
std::ostream& operator<<(const std::ostream& os, const Bureaucrat& other);

#endif