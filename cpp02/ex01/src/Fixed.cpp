

#include "Fixed.hpp"
const int Fixed::_fracBits = 8;

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixPoint(value << Fixed::_fracBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixPoint(static_cast<int>(roundf(value *(1 << Fixed::_fracBits)))) 
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixPoint = other._fixPoint;
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
    return this->_fixPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixPoint = raw;
}


float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_fixPoint) / (1 << Fixed::_fracBits));
}


int Fixed::toInt(void) const
{
    return (this->_fixPoint >> Fixed::_fracBits); 
}


std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}