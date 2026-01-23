#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), 
FragTrap(), ScavTrap(), _name("Default")
{
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "Constructor DiamondTrap Default called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
FragTrap(name), ScavTrap(name), _name(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "Constructor DiamondTrap called for "
              << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
 FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called\n";
    // *this = other; i dont need  because copy from parent classes
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap assignment operator called\n";
    if (this != &other)
    {
        this->_name = other._name;
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor DiamondTrap called for "
              << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap here! My name is "
              << this->_name << "!\n" << "ClapTrap here! My name is "
              << ClapTrap::_name << std::endl;
}

