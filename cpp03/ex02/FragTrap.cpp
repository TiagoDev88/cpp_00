

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Constructor FragTrap default called"
              << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "Constructor FragTrap called for "
              << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copy Constructor FragTrap called from "
              << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy operator FragTrap called\n";
    if (this != &other)
    {
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._hitPoints;
        this->_name = other._name;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap called for "
              << this->_name << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->_name << "high five!"
              << std::endl;
}