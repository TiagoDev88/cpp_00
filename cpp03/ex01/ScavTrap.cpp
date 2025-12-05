
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Constructor ScavTrap default called\n";
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

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copy Constructor ScavTrap called from "
              << getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor ScavTrap called for "
              << this->getName() << std::endl;

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
    if (this->getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() <<
                 " is dead! " << 
                 "Since it's dead, it doesn't attack, or is it a zombie?"
                 << std::endl;
        return;
    }
    if (this->getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << this->getName() <<
                 " dont have energy points!" << std::endl;
        return;
    }

    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ScavTrap " << this->getName() << " attacks "
              << target << ", causing "
              << this->getAttackDamage() << " points of damage!"
              << " And now has "
              << this->getEnergyPoints() << " energy points! "
              << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName()
              << " is now in Gate keeper mode."
              << std::endl;
}