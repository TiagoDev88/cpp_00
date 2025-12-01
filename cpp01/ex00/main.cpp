

#include "Zombie.hpp"

int main(void)
{
	Zombie *tiago_heap;
	
	tiago_heap = newZombie("TIAGO_HEAP");
	tiago_heap->announce();
	delete tiago_heap;

	randomChump("Kiko_STACK");
	return 0;
}