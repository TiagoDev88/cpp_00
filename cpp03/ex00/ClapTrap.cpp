

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
                 " dont have energyPoints!" << std::endl;
        return;
    }
    if(this->_attackDamage == 0)
    {
        std::cout << "Claptrap " << this->_name << " attacks "
                  << target << ", causing " << this->_attackDamage
                  << " points of damage! Then nothing happens"
                  << " And you have now " << this->_energyPoints 
                  << " energy points! " << std::endl;
        this->_energyPoints--;
        return;
    }
    this->_energyPoints--;
    std::cout << "Claptrap " << this->_name << " attacks "
              << target << ", causing " << this->_attackDamage
              << " points of damage!" << " And you have now "
              << this->_energyPoints << " energy points! "
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    //When ClapTrap attacks, it causes its
    // target to lose <attack damage> hit points.
    if (this->_hitPoints == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << "is dead! Don't hit dead people!" << std::endl;
        return;
    }
    if (this->_hitPoints < amount)
    {
        std::cout << "Claptrap " << this->_name
                  << " died with " << amount 
                  << " points of damage!" << std::endl;
        this->_hitPoints = 0;
        return;
    }

    std::cout << "Claptrap " << this->_name
          << " received attack with " << amount 
          << " points of damage!" << std::endl;
    this->_hitPoints -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    //When ClapTrap repairs itself, it regains <amount> hit points.
    if (this->_energyPoints == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << "! You don't have enough points to heal yourself."
                  << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints +=amount;
    std::cout << "Claptrap " << this->_name
              << " You gain " << amount 
              << "of health!" << " And you have " 
              << "now " << this->_energyPoints 
              << " energy points! " << std::endl;
}
