#include "DiamondTrap.hpp"

int main(void) {

    std::cout << "--- construction: watch for EXACTLY ONE ClapTrap message ---" << std::endl;
    DiamondTrap d("Diana");

    std::cout << "\n--- whoAmI: two different names expected ---" << std::endl;
    d.whoAmI();

    std::cout << "\n--- attributes: hp from FragTrap, energy from ScavTrap, dmg from FragTrap ---" << std::endl;
    d.attack("wall");

    std::cout << "\n--- both parents' special abilities are inherited ---" << std::endl;
    d.whoAmI();

    std::cout << "\n--- inherited takeDamage/beRepaired still work ---" << std::endl;
    d.takeDamage(20);
    d.beRepaired(5);

    std::cout << "\n--- draining energy: should take exactly 50 attacks (ScavTrap's value) ---" << std::endl;
    DiamondTrap e("Elle");
    for (int n = 0; n < 50; n++)
        e.attack("wall");
    e.attack("wall");

    std::cout << "\n--- copy constructor: name must transfer correctly ---" << std::endl;
    DiamondTrap f(d);
    f.whoAmI();

    std::cout << "\n--- copy assignment: name must transfer correctly ---" << std::endl;
    DiamondTrap g("Gwen");
    g = d;
    g.whoAmI();

    std::cout << "\n--- end of main: watch destructor count per object ---" << std::endl;
    return 0;
}