

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Constructor WrongCat default called\n";
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "Copy Constructor WrongCat called from "
              << other._type << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Copy assignment operator WrongCat called"
              << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor WrongCat called from "
              << this->_type << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat Mewo Mewo!" << std::endl;
}