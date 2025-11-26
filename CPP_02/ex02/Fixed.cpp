
#include "Fixed.hpp"

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    this->_fixPoint = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const int value)
{
    std::cout << "int constructor\n";
    this->_fixPoint = (value << _fracBits);
}
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixPoint(other.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixPoint = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fixPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixPoint = raw;
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_fixPoint) / (1 << _fracBits));
}

int Fixed::toInt( void ) const
{
    return (_fixPoint >> _fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}