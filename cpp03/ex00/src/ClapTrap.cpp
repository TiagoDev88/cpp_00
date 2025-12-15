

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor default called\n";
}

ClapTrap::ClapTrap(std::string name) :  _name(name),
_hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "Constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy Constructor called from "
              << other._name << std::endl;
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
    std::cout << "Destructor called for "
              << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "Claptrap " << this->_name <<
                 " is dead! " << 
                 "Since it's dead, it doesn't attack, or is it a zombie?"
                 << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "Claptrap " << this->_name <<
                 " dont have energy points!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "Claptrap " << this->_name << " attacks "
              << target << ", causing " << _attackDamage
              << " points of damage!" << " And now has "
              << this->_energyPoints << " energy points! "
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << " is dead! Please dont hit me!" << std::endl;
        return;
    }
    if (this->_hitPoints <= amount)
    {
        std::cout << "Claptrap " << this->_name
                  << " died with " << amount 
                  << " points of damage!" << std::endl;
        this->_hitPoints = 0;
        return;
    }
    if (amount == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << " received attack with " << amount 
                  << " points of damage and nothing happens!"
                  << std::endl;
        return;
    }
    this->_hitPoints -= amount;
    std::cout << "Claptrap " << this->_name
          << " received attack with " << amount 
          << " points of damage!" << " And now has "
          << this->_hitPoints << " HP!"
          << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << " don't have enough points to heal yourself."
                  << std::endl;
        return;
    }
    this->_energyPoints--;
    if (amount == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << " can't heal with 0 amount!"
                  << " But cost 1 energy point!"
                  << std::endl;
        return;
    }
    if (static_cast<long long>(this->_hitPoints) + amount > 4294967295)
    {
        this->_hitPoints = 4294967295; //uint max value
        std::cout << "Claptrap " << this->_name
                  << " obtained max value of hit points!"
                  << " Has " << this->_hitPoints << " HP and "
                  << this->_energyPoints << " energy points!"
                  << std::endl;
        return;
    }
    else
        this->_hitPoints +=amount;
    std::cout << "Claptrap " << this->_name
              << " gain " << amount 
              << " HP!" << " Has "
              << this->_hitPoints << " HP and " 
              << this->_energyPoints << " energy points!" 
              << std::endl;
}
