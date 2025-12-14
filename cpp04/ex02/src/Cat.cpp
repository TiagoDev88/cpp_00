

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Constructor Cat default called\n";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy Constructor Cat called from "
              << other._type << std::endl;
    this->_brain = new Brain(*other._brain);
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
    delete this->_brain;
    std::cout << "Destructor Cat called from "
              << this->_type << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Mewo Mewo!" << std::endl;
}