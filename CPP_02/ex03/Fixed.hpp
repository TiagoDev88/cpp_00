#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int _fixPoint;
    static const int _fracBits;

    public:
    //Default constructor
    Fixed();
    //constructor with int
    Fixed(const int value);
    //constructor with float
    Fixed(const float value);
    //copy constructor, The constructor is called when create a new object from another.
    Fixed(const Fixed& other);
    //Destructor
    ~Fixed();
    //copy assignment, Copy data from one object to another existing one
    Fixed& operator=(const Fixed& other);

    //comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    //arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    //increment/decrement operators
    //pre-increment
    Fixed& operator++();
    //post-increment
    Fixed operator++(int);
    //pre-decrement
    Fixed& operator--();
    //post-decrement
    Fixed operator--(int);

    //min and max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    //member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif