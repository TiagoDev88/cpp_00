

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"



void testClapTrap();
void testScavTrap();
void testFragTrap();

int main(void)
{
    testClapTrap();
    std::cout << "---------------------------------------------------------------" << std::endl;
    testScavTrap();
    std::cout << "---------------------------------------------------------------" << std::endl;
    testFragTrap();
    
    return 0;
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

void testScavTrap()
{
    ScavTrap scav1("ScavengerOne");
    ScavTrap scav2("ScavengerTwo");
    ScavTrap clone("clone");
    scav1.attack("an intruder");
    scav1.takeDamage(100);
    clone = scav1;
    clone.takeDamage(1); //is dead. because copy from scav1.
    scav1.beRepaired(20);
    clone.takeDamage(1); //is dead. because copy from scav1.
    scav1.guardGate();
    scav2.takeDamage(30);
    scav2.beRepaired(20);
    scav2.attack("zombie");
}

void testFragTrap()
{
    FragTrap ft;
    FragTrap ft1("Malaquias");
    FragTrap ft2("Zeca Afonso");

    ft.attack("tone");
    ft.takeDamage(99);
    ft = ft2;
    ft.takeDamage(99);
    ft = FragTrap("Joaquina");
    ft2.beRepaired(100);
    ft2.takeDamage(100);
    ft2.takeDamage(100);
    ft1.attack("tiburcio");
    ft1.takeDamage(500);
}
