
#include "Fixed.hpp"
const int Fixed::_fracBits = 8;


Fixed::Fixed() : _fixPoint(0) {}

// (1 << _fracBits) = 256 , value * 256
Fixed::Fixed(const float value) : _fixPoint(static_cast<int>(roundf(value * (1 << Fixed::_fracBits)))) {}

Fixed::Fixed(const int value)
{
    this->_fixPoint = (value << Fixed::_fracBits);
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) 
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_fixPoint = other._fixPoint;
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

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_fixPoint) / (1 << Fixed::_fracBits));
}

int Fixed::toInt( void ) const
{
    return (_fixPoint >> Fixed::_fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return os;
}

//comparison operators
bool Fixed::operator>(const Fixed& other) const
{
    if (this->getRawBits() > other.getRawBits())
        return (true);
    else
        return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->getRawBits() < other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->getRawBits() >= other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->getRawBits() <= other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->getRawBits() == other.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->getRawBits() != other.getRawBits())
        return true;
    else
        return false;
}

//arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed tmp;
    tmp._fixPoint = this->_fixPoint + other._fixPoint;
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed tmp;
    tmp._fixPoint = this->_fixPoint - other._fixPoint;
    return (tmp);
}

// multiply and then shift right by _fracBits to maintain precision
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result._fixPoint = ((this->_fixPoint * other._fixPoint) >> Fixed::_fracBits);
    return result;
}
// shift _fixPoint left by _fracBits before division to maintain precision
// then perform the division and return the result
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed tmp;
    tmp._fixPoint = ((this->_fixPoint << Fixed::_fracBits) / other._fixPoint);
    return (tmp);
}

//increment/decrement operators
//pre-increment
Fixed& Fixed::operator++()
{
    ++this->_fixPoint;
    return (*this);
}

//post-increment
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fixPoint++;
    return (tmp);
}

//pre-decrement
Fixed& Fixed::operator--()
{
    --this->_fixPoint;
    return (*this);
}

//post-decrement
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fixPoint--;
    return (tmp);
}

//min and max functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}