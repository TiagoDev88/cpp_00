

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10),
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

    this->_energyPoints--;
    std::cout << "Claptrap " << this->_name << " attacks "
              << target << ", causing " << _attackDamage
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
          << " points of damage!" << " And now, have "
          << this->_hitPoints << " health!"
          << std::endl;
}
//TODO: verificar se o amount e' negativo
// talvez printar a vida que tenho.
void ClapTrap::beRepaired(unsigned int amount)
{
    //When ClapTrap repairs itself, it regains <amount> hit points.
    if (amount == 0)
    {
        std::cout << "Claptrap " << this->_name
                  << "! You can't heal with 0 amount!"
                  << " But cost 1 energy point!"
                  << std::endl;
        this->_energyPoints--;
        return;
    }
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
              << " of health!" << " And you have "
              << this->_hitPoints << " of health! And you have now " 
              << this->_energyPoints << " energy points!" 
              << std::endl;
}
