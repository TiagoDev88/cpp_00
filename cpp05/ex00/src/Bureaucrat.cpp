#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(42) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
    if (grade > MIN_GRADE)
        GradeTooLowException();
    if (grade < MAX_GRADE)
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
    if (this->_grade <= MAX_GRADE)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrement()
{
    if (this->_grade >= MIN_GRADE)
        throw GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << other.getName() << ", bureaucrat grade "
        << other.getGrade() << ".";

    return os;
}
