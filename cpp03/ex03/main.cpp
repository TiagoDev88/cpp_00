#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== TESTE DIAMONDTRAP =====" << std::endl;

    DiamondTrap dt1("Bob");

    std::cout << "\n--- WHO AM I ---" << std::endl;
    dt1.whoAmI();

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

// #include "DiamondTrap.hpp"
// #include <iostream>

// int main() {
//     DiamondTrap dt("Bob");

//     dt.whoAmI();
//     dt.attack("Enemy");
//     dt.takeDamage(20);
//     dt.beRepaired(10);

//     std::cout << "\nCopying...\n";
//     DiamondTrap copy(dt);
//     copy.whoAmI();

//     return 0;
// }

/*OUTPUT

DiamondTrap constructor called for Bob
DiamondTrap name: Bob
ClapTrap name: Bob_clap_name
ScavTrap Bob_clap_name attacks Enemy, causing XX damage!
ClapTrap Bob_clap_name received attack...
ClapTrap Bob_clap_name gain HP...
DiamondTrap copy constructor called
DiamondTrap name: Bob
ClapTrap name: Bob_clap_name

*/