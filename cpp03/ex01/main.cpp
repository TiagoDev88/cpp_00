

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testScavTrap()
{
    ScavTrap scav1("ScavengerOne");
    ScavTrap scav2("ScavengerTwo");
    scav1.attack("an intruder");
    scav1.guardGate();
    scav2.takeDamage(30);
    scav2.beRepaired(20);
}

void testClapTrap()
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
    test.beRepaired(4294967295);
    test.beRepaired(4294967295);
    test.beRepaired(4294967295); 
}

int main(void)
{
    testClapTrap();
    std::cout << "---------------------" << std::endl;
    testScavTrap();
    
    return 0;
}