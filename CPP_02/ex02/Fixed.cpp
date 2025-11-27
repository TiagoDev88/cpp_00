
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
    Fixed tmp = this->getRawBits() + other.getRawBits();
    return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed tmp = this->getRawBits() - other.getRawBits();
    return (tmp);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed tmp = this->getRawBits() * other.getRawBits();
    return (tmp);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed tmp = this->getRawBits() / other.getRawBits();
    return (tmp);
}

//increment/decrement operators
//pre-increment
Fixed& Fixed::operator++()
{
    this->_fixPoint++;
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
    this->_fixPoint--;
    return (*this);
}

//post-decrement
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fixPoint--;
    return (tmp);
}

// //min and max functions
// static Fixed& min(Fixed& a, Fixed& b)
// {

// }

// static const Fixed& min(const Fixed& a, const Fixed& b)
// {

// }

// static Fixed& max(Fixed& a, Fixed& b)
// {

// }

// static const Fixed& max(const Fixed& a, const Fixed& b)
// {

// }