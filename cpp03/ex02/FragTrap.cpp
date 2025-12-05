

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "Constructor FragTrap default called"
              << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "Constructor FragTrap called for "
              << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "Copy Constructor FragTrap called from "
              << other.getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy operator FragTrap called\n";
    if (this != &other)
    {
        this->setAttackDamage(other.getAttackDamage());
        this->setEnergyPoints(other.getEnergyPoints());
        this->setHitPoints(other.getHitPoints());
        this->setName(other.getName());
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor FragTrap called for "
              << this->getName() << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << this->getName() << "high five!"
              << std::endl;
}