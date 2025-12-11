

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Constructor Dog default called\n";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Copy Constructor Dog called from "
              << other._type << std::endl;
    this->_brain = new Brain(*other._brain);
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
    delete this->_brain;
    std::cout << "Destructor Dog called from "
              << this->_type << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Auf Auf!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return this->_brain;
}