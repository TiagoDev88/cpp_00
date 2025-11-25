

#include "Fixed.hpp"

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixPoint = other.getRawBits();
    return *this;
}

Fixed& Fixed::operator<<(const Fixed& other)
{

}

Fixed::Fixed(const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixPoint = raw;
}

float Fixed::toFloat(void) const
{
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    std::cout << "Int constructor called" << std::endl;
}