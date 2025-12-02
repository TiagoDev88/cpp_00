

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10),
 _attackDamage(0), _name("Default")
{
    std::cout << "Constructor default called\n";
}

ClapTrap::ClapTrap(std::string name) :  _hitPoints(10), _energyPoints(10),
 _attackDamage(0), _name(name)
{
    std::cout << "Constructor with params called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy Constructor called\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy operator called\n";
    if (this != &other)
    {
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._hitPoints;
        this->_name = other._name;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    //Attacking and repairing each cost 1 energy point.
    std::cout << "Claptrap " << this->_name << " attacks "
              << target << ", causing " << this->_attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    //When ClapTrap attacks, it causes its
    // target to lose <attack damage> hit points.

}

void ClapTrap::beRepaired(unsigned int amount)
{
    //When ClapTrap repairs itself, it regains <amount> hit points.

}