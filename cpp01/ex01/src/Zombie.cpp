

#include "../inc/Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Constructor" << std::endl;
    _name = "noName";
}

Zombie::~Zombie(){}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}