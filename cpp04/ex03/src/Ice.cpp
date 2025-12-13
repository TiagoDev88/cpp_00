#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other)
{
    this->_type = other._type;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        this->_type = other._type;
    }
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
    return new Ice(); //talvez tenha que colocar o proprio objeto que esta a ser chamado Ice(*this)
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " 
              << target.getName() << " *" << std::endl;
}