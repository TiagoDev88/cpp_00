
#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _signed(false), _gradeSign(42), _gradeExec(24) {}

Form::Form(std::string name, const int gradeSign, const int gradeExec) :
 _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
 {
    if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
        throw GradeTooLowException();
    else if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
        throw GradeTooHighException();
 }

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

Form::~Form() {}

const std::string Form::getName() const {return _name;}

bool Form::getSigned() const {return _signed;}

int Form::getGradeSignIt() const {return _gradeSign;}

int Form::getGradeExecIt() const {return _gradeExec;}

void Form::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    else
        _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
    os << "Form Name: " << other.getName() << ", Signed: "
    << (other.getSigned() ? "Signed!" : "Not Signed!")
    << ", Grade Required to Sign: " << other.getGradeSignIt()
    << ", Grade Required to Execute: " << other.getGradeExecIt();
    return os;
}
