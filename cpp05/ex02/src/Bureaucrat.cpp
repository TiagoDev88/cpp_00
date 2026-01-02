#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(42) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 
_name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

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

void Bureaucrat::executeForm(AForm const &form) const
{
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->_name << " couldn't execute "
                  << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << other.getName() << ", bureaucrat grade "
        << other.getGrade() << ".";

    return os;
}

void Bureaucrat::signForm(AForm& form) const
{
    try 
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign "
                  << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

//TODO fazer um try catch para se posso imprimir a msg "<bureaucrat> executed <form>"
//caso nao possa, imprimir a dizer que nao foi possivel porque... e.what() e mostra o porque.