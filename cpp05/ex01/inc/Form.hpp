#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "../../ex00/inc/Bureaucrat.hpp"


class Form
{
    private:
    const std::string _name;
    bool _signed;
    const int gradeSignIt;
    const int gradeExecIt;

    public:
    Form();
    Form(std::string name, bool _signed, const int gradeSign, const int gradeExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string getName() const;
    bool getSigned() const;
    int getGradeSignIt() const;
    int getGradeExecIt() const;

    //talvez void porque como vou passar referencia nao preciso retornar nada.
    void beSigned(const Bureaucrat& other);

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

};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif FORM_HPP