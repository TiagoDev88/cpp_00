#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

#define MAX_GRADE 1
#define MIN_GRADE 150


class AForm
{
    private:
    const std::string _name;
    bool _signed;
    const int _gradeSign;
    const int _gradeExec;

    // porque tem que ser acessivel as subclasses.
    protected:
    virtual void executeAction() const = 0;

    public:
    AForm();
    AForm(std::string name, const int gradeSign, const int gradeExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string getName() const;
    bool getSigned() const;
    int getGradeSignIt() const;
    int getGradeExecIt() const;

    void beSigned(const Bureaucrat& other);
    void execute(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception
    {
        public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif