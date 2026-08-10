#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

    std::cout << "--- ScavTrap construction/destruction chaining ---" << std::endl;
    {
        ScavTrap s("Sam");
        std::cout << "s constructed, now destroying it..." << std::endl;
    }

    std::cout << "\n--- default ScavTrap construction ---" << std::endl;
    ScavTrap def;

    std::cout << "\n--- ScavTrap attributes correctly overridden ---" << std::endl;
    ScavTrap t("Tank");
    t.attack("wall");

    std::cout << "\n--- ScavTrap-specific ability ---" << std::endl;
    t.guardGate();

    std::cout << "\n--- inherited functions still work unmodified ---" << std::endl;
    t.takeDamage(30);
    t.beRepaired(10);

    std::cout << "\n--- draining ScavTrap's energy (50 points) ---" << std::endl;
    ScavTrap u("Ursa");
    for (int n = 0; n < 50; n++)
        u.attack("wall");
    u.attack("wall");

    std::cout << "\n--- ScavTrap copy constructor ---" << std::endl;
    ScavTrap v(t);
    v.attack("copy-test");

    std::cout << "\n--- ScavTrap copy assignment ---" << std::endl;
    ScavTrap w("Wendy");
    w = t;
    w.attack("assign-test");

    std::cout << "\n--- end of main ---" << std::endl;
    return 0;
}