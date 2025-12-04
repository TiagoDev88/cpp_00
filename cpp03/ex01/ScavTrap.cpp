
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Constructor default ScavTrap called\n";
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor ScavTrap called for " << name << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}
ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "Copy Constructor ScavTrap called\n";
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called\n";

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy operator ScavTrap called\n";
    if (this != &other)
    {
        this->setName(other.getName());
        this->setAttackDamage(other.getAttackDamage());
        this->setEnergyPoints(other.getEnergyPoints());
        this->setHitPoints(other.getHitPoints());
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << this->getName() << " attacks "
              << target << ", causing "
              << this->getAttackDamage() << " points of damage!"
              << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}