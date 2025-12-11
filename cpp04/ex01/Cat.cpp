

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Constructor Cat default called\n";
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Copy Constructor Cat called from "
              << other._type << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator Cat called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor Cat called from "
              << this->_type << std::endl;
    delete this->_brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Mewo Mewo!" << std::endl;
}