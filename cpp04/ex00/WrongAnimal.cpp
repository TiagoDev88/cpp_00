

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "Constructor WrongAnimal default called\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "Constructor WrongAnimal called with type "
              << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "Copy Constructor WrongAnimal called from "
              << other._type << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Copy assignment operator WrongAnimal called"
              << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor WrongAnimal called from "
              << this->_type << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}
