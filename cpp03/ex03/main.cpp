#include <iostream>
#include "DiamondTrap.hpp"

void testDiamondProblem()
{
    std::cout << "========================================\n";
    std::cout << "DIAMOND PROBLEM TEST\n";
    std::cout << "========================================\n\n";

    std::cout << "--- Test 1: Single ClapTrap Instance Check ---\n";
    std::cout << "Creating DiamondTrap 'Alpha'...\n";
    std::cout << "Expected: Only ONE ClapTrap constructor call\n";
    
    DiamondTrap dt1("Alpha");
    
    std::cout << "\n--- Test 2: Name Resolution ---\n";
    dt1.whoAmI();
    std::cout << "Expected: DiamondTrap name = Alpha, ClapTrap name = Alpha_clap_name\n\n";

    std::cout << "--- Test 3: Method Resolution ---\n";
    std::cout << "Attack should use ScavTrap's implementation:\n";
    dt1.attack("Target1");
    std::cout << "\n";

    std::cout << "--- Test 4: Attribute Inheritance ---\n";
    std::cout << "HP should be from FragTrap (100)\n";
    std::cout << "Energy should be from ScavTrap (50)\n";
    std::cout << "Attack Damage should be from FragTrap (30)\n";
    dt1.takeDamage(20);
    dt1.beRepaired(10);
    std::cout << "\n";

    std::cout << "--- Test 5: Copy Constructor ---\n";
    std::cout << "Creating copy of 'Alpha'...\n";
    DiamondTrap dt2(dt1);
    std::cout << "Copy should also have only ONE ClapTrap instance\n";
    dt2.whoAmI();
    std::cout << "\n";

    std::cout << "--- Test 6: Assignment Operator ---\n";
    DiamondTrap dt3("Beta");
    std::cout << "\nAssigning 'Alpha' to 'Beta'...\n";
    dt3 = dt1;
    dt3.whoAmI();
    std::cout << "\n";

    std::cout << "--- Test 7: Independent Copies ---\n";
    std::cout << "Modifying copy should not affect original:\n";
    dt2.attack("Target2");
    dt2.takeDamage(50);
    std::cout << "\nOriginal state:\n";
    dt1.whoAmI();
    dt1.attack("Target3");
    std::cout << "\n";

    std::cout << "--- Test 8: Destruction Order ---\n";
    std::cout << "Expected order: ~DiamondTrap -> ~ScavTrap -> ~FragTrap -> ~ClapTrap\n";
    std::cout << "Each object should destroy only ONE ClapTrap instance\n";
}

void testEdgeCases()
{
    std::cout << "\n========================================\n";
    std::cout << "EDGE CASES TEST\n";
    std::cout << "========================================\n\n";

    std::cout << "--- Test 1: Default Constructor ---\n";
    DiamondTrap dt_default;
    dt_default.whoAmI();
    std::cout << "\n";

    std::cout << "--- Test 2: Empty Name ---\n";
    DiamondTrap dt_empty("");
    dt_empty.whoAmI();
    std::cout << "\n";

    std::cout << "--- Test 3: Energy Depletion ---\n";
    DiamondTrap dt_energy("Exhausted");
    std::cout << "Performing 51 attacks (ScavTrap has 50 energy):\n";
    for (int i = 0; i < 51; i++)
    {
        dt_energy.attack("Dummy");
    }
    std::cout << "\n";

    std::cout << "--- Test 4: HP Depletion ---\n";
    DiamondTrap dt_hp("Mortal");
    std::cout << "Taking 100 damage (FragTrap has 100 HP):\n";
    dt_hp.takeDamage(100);
    dt_hp.attack("Ghost");
    dt_hp.beRepaired(50);
    std::cout << "\n";
}


int main()
{
    testDiamondProblem();
    testEdgeCases();

    std::cout << "\n========================================\n";
    std::cout << "ALL TESTS COMPLETED\n";
    std::cout << "========================================\n";
    std::cout << "\nIf you saw:\n";
    std::cout << "  ✓ Only ONE ClapTrap constructor per DiamondTrap\n";
    std::cout << "  ✓ Clean name resolution (no ambiguity)\n";
    std::cout << "  ✓ Proper method calls (ScavTrap attack)\n";
    std::cout << "  ✓ Correct attribute values (FragTrap HP, ScavTrap Energy)\n";
    std::cout << "\nThen virtual inheritance is working correctly!\n";

    return 0;
}