

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Constructor default called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "Constructor with params called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy Constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy operator called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{

}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}