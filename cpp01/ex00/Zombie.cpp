

#include "Zombie.hpp"

Zombie::Zombie(std::string name){

	std::cout << name << " Constructor called" << std::endl;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " has been destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
