

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trapTiago("Tiago");
    ClapTrap trapKiko("Kiko");
    ClapTrap noName;
    trapTiago.takeDamage(5);
    for (int i = 0; i< 11; i++)
        trapTiago.attack("Kiko");
    for (int i = 0; i < 11; i++)
        trapKiko.takeDamage(1);
    trapKiko.takeDamage(0);
    noName.beRepaired(100);
    noName.beRepaired(100);
    for (int i = 0; i < 11; i++)
        noName.takeDamage(25);
    ClapTrap cloneTiago(trapTiago);
    cloneTiago.attack("Alberto"); // dont attack because dont have EnergyPoints.
    ClapTrap test;
    test.beRepaired(UINT_MAX);
    test.beRepaired(UINT_MAX);
    test.beRepaired(UINT_MAX); 
    return 0;
}