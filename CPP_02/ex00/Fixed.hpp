
#include <iostream>

class Fixed
{
    private:
    int _fixPoint;
    static const int _fracBits = 8;

    public:
    //Default constructor
    Fixed();
    //copy constructor, The constructor is called when create a new object from another.
    Fixed(const Fixed& other);
    //copy assignment, Copy data from one object to another existing one
    Fixed& operator=(const Fixed& other); 
    //Destructor
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

};