

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Constructor Animal default called\n";
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Constructor Animal called with type "
              << this->_type << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy Constructor Animal called from "
              << other._type << std::endl;
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator Animal called"
              << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor Animal called from "
              << this->_type << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}
