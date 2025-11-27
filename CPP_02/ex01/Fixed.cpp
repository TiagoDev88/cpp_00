

#include "Fixed.hpp"
const int Fixed::_fracBits = 8;

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// value << 8 is value * 256, because 2^8 = 256 , so we shift left by 8 bits
Fixed::Fixed(const int value) : _fixPoint(value << Fixed::_fracBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// (1 << _fracBits) = 256 , value * 256
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

Fixed::Fixed(const Fixed& other) : _fixPoint(other._fixPoint)
{
    std::cout << "Copy constructor called" << std::endl;
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

 // _fixPoint / 256.0f
float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_fixPoint) / (1 << Fixed::_fracBits));
}

// _fixPoint / 256, because 2^8 = 256 , so we shift right by 8 bits
int Fixed::toInt(void) const
{
    return (this->_fixPoint >> Fixed::_fracBits); 
}

// const because Fixed is const value or not
std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}