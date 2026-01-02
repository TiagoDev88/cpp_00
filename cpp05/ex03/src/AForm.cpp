
#include "AForm.hpp"

AForm::AForm() : _name("DefaultAForm"), _signed(false), _gradeSign(42), _gradeExec(24) {}

AForm::AForm(std::string name, const int gradeSign, const int gradeExec) :
 _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
 {
    if (gradeSign > MIN_GRADE || gradeExec > MIN_GRADE)
        throw GradeTooLowException();
    else if (gradeSign < MAX_GRADE || gradeExec < MAX_GRADE)
        throw GradeTooHighException();
 }

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed),
_gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const {return _name;}

bool AForm::getSigned() const {return _signed;}

int AForm::getGradeSignIt() const {return _gradeSign;}

int AForm::getGradeExecIt() const {return _gradeExec;}

void AForm::beSigned(const Bureaucrat& other)
{
    if (other.getGrade() > this->_gradeSign)
        throw GradeTooLowException();
    else
        _signed = true;
}

//TODO criar aqyu a funcao executem para ver se esta assinado ou nao.
// criar uma verificacao para fazer um throw se o AFormulario esta assinado ou nao.
// verificar se o grade esta dentro do limite para ser assinado.
//caso passe tudo, executo a acao.

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
    os << "AForm Name: " << other.getName() << ", Signed: "
    << (other.getSigned() ? "Signed!" : "Not Signed!")
    << ", Grade To Sign: " << other.getGradeSignIt()
    << ", Grade To Execute: " << other.getGradeExecIt();
    return os;
}
