
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Constructor ScavTrap default called\n";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor ScavTrap called for " << name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copy Constructor ScavTrap called from "
              << other._name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called for "
              << this->_name << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy operator ScavTrap called\n";
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._hitPoints;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name <<
                 " is dead! " << 
                 "Since it's dead, it doesn't attack, or is it a zombie?"
                 << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name <<
                 " dont have energy points!" << std::endl;
        return;
    }

    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks "
              << target << ", causing "
              << this->_attackDamage << " points of damage!"
              << " And now has "
              << this->_energyPoints << " energy points! "
              << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name
              << " is now in Gate keeper mode."
              << std::endl;
}