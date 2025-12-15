
#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie zombie_in_stack(name);
	zombie_in_stack.announce();
}