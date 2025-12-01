

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* zombie_in_heap = new Zombie(name);
	return zombie_in_heap;
}