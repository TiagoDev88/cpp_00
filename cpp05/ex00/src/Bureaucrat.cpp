#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(42) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
    if (grade > 150)
        GradeTooLowException();
    else if (grade < 1)
        GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increment()
{
    if (this->_grade == 1)
        throw G
        // GradeTooHighException(); //nao sei se tenho que dar erro e return.
    if (this->_grade > 0 && this->_grade < 151)
        this->_grade--;
}

void Bureaucrat::decrement()
{
    if (this->_grade == 150)
        GradeTooLowException(); //nao sei se tenho que dar erro e return.
    if (this->_grade > 0 && this->_grade < 151)
        this->_grade++;
}

void Bureaucrat::GradeTooHighException() const
{
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void Bureaucrat::GradeTooLowException() const
{

}