

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newGun) : _name(newName), _gun(newGun){}

HumanA::~HumanA(){}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _gun.getType() << std::endl;
}