#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <exception>

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

    //talvez chamar a form para passar aqui na funcao.
    void signForm();

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