


#include "HumanB.hpp"

HumanB::HumanB(std::string newName) : _name(newName), _gun(NULL){}

HumanB::~HumanB(){}

void HumanB::attack()
{
    if (_gun)
        std::cout << _name << " attacks with their " << _gun->getType() << std::endl;
    else
        std::cout << _name << " has no weapon to attack with!" << std::endl;
}

void HumanB::setWeapon(Weapon& newGun)
{
    this->_gun = &newGun;
}