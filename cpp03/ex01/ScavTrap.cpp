
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Constructor default ScavTrap called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "Copy Constructor ScavTrap called\n";

}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {

    }
}

void attack(const std::string& target)
{

}

void takeDamage(unsigned int amount)
{

}

void beRepaired(unsigned int amount)
{

}

void guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}