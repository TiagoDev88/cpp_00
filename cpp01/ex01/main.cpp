
#include "Zombie.hpp"

int main(void)
{
    int n = 7;
    std::string name = "Kiko";
    Zombie* horde = zombieHorde(n, name);

    for (int i = 0; i < n; i++)
        horde[i].announce();

    delete[] horde;
}