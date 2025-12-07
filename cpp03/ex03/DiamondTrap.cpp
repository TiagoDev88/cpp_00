

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default")
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Constructor Default called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Constructor called for "
              << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap Copy Constructor from "
              << other._name << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
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
    std::cout << "Destructor called for "
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


/*

DiamondTrap::DiamondTrap()
{
    _name = "default";
    ClapTrap::name = _name + "_clap_name";

    // Atributos vêm dos pais
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
    _name = name;
    ClapTrap::name = name + "_clap_name";

    // herdado dos pais (sem virtual → temos que escolher manualmente)
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap constructor called for " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        ClapTrap::name = other.ClapTrap::name;

        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << _name << "\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << "\n";
    std::cout << "ClapTrap name: " << ClapTrap::name << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
    // ScavTrap version
    ScavTrap::attack(target);
}

*/