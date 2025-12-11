

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Constructor Dog default called\n";
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Copy Constructor Dog called from "
              << other._type << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator Dog called"
              << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor Dog called from "
              << this->_type << std::endl;
    delete this->_brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Auf Auf!" << std::endl;
}