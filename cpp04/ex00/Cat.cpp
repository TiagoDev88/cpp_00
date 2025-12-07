

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Constructor Cat default called\n";
    this->_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy Constructor Cat called from "
              << other._type << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator Cat called"
              << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor Cat called from "
              << this->_type << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Mewo Mewo!" << std::endl;
}