#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat
{
    private:
    const std::string _name;
    unsigned int         _grade;

    public:
    Bureaucrat();
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    int increment(const unsigned int grade);
    int decrement(const unsigned int grade);


};
//TODO: talvez tirar o const do std::ostream& os, testar e logo vejo.
std::ostream& operator<<(const std::ostream& os, const Bureaucrat& other);

#endif