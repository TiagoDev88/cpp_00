

#include "Fixed.hpp"

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixPoint(value << _fracBits) // value << 8 is value * 256
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixPoint(roundf(value *(1 << _fracBits))) // (1 << _fracBits) = 256 , value * 256
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixPoint = other.getRawBits();
    return *this;
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
    return (static_cast<float>(_fixPoint) / static_cast<float>(1 << _fracBits)); // _fixPoint / 256.0f
}

int Fixed::toInt(void) const
{
    return (_fixPoint >> _fracBits); // _fixPoint / 256, because 2^8 = 256 , so we shift right by 8 bits
}