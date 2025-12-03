

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap;
    ClapTrap jose("jose");
    ClapTrap tiago("tiago");
    ClapTrap tia("tiagoTIA");

    trap.attack("jose1");
    trap.beRepaired(20);
    trap.takeDamage(5);

    jose.attack("JOSE");
    jose.takeDamage(11);
    jose.beRepaired(5);

    tiago.attack("TIAGO");
    tiago.takeDamage(9);
    tiago.beRepaired(0);

    tia.beRepaired(-1);
    return 0;
}