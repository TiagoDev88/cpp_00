#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <exception>
#include "AForm.hpp"


class AForm;

#define MAX_GRADE 1
#define MIN_GRADE 150


class Bureaucrat
{
    private:
    const std::string _name;
    int         _grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    void signForm(AForm& form) const;
    
    void executeForm(const AForm &form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif