#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== TESTE DIAMONDTRAP =====" << std::endl;

    DiamondTrap dt1("Bob");

    std::cout << "\n--- WHO AM I ---" << std::endl;
    dt1.whoAmI();

    std::cout << "\n--- STATS INICIAIS ---" << std::endl;
    std::cout << "Hitpoints:  " << dt1.getHitPoints() << std::endl;
    std::cout << "Energy:     " << dt1.getEnergyPoints() << std::endl;
    std::cout << "Attack dmg: " << dt1.getAttackDamage() << std::endl;

    std::cout << "\n--- ATAQUE ---" << std::endl;
    dt1.attack("Inimigo");

    std::cout << "\n--- TOMAR DANO ---" << std::endl;
    dt1.takeDamage(30);

    std::cout << "\n--- REPARAR ---" << std::endl;
    dt1.beRepaired(20);

    std::cout << "\n--- WHO AM I (NOVAMENTE) ---" << std::endl;
    dt1.whoAmI();

    std::cout << "\n===== FIM DOS TESTES =====" << std::endl;

    return 0;
}
