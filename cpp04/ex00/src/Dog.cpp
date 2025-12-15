

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Constructor Dog default called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy Constructor Dog called from "
              << other._type << std::endl;
    this->_type = other._type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator Dog called"
              << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor Dog called from "
              << this->_type << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Auf Auf!" << std::endl;
}