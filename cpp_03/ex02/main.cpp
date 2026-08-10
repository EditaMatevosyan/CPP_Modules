#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

    std::cout << "--- FragTrap construction/destruction chaining ---" << std::endl;
    {
        FragTrap f("Fiona");
        std::cout << "f constructed, now destroying it..." << std::endl;
    }

    std::cout << "\n--- default FragTrap construction ---" << std::endl;
    FragTrap def;

    std::cout << "\n--- FragTrap attributes correctly overridden ---" << std::endl;
    FragTrap g("Gus");
    g.attack("wall");

    std::cout << "\n--- FragTrap-specific ability ---" << std::endl;
    g.highFivesGuys();

    std::cout << "\n--- inherited functions still work unmodified ---" << std::endl;
    g.takeDamage(40);
    g.beRepaired(15);

    std::cout << "\n--- draining FragTrap's energy (100 points) ---" << std::endl;
    FragTrap h("Hugo");
    for (int n = 0; n < 100; n++)
        h.attack("wall");
    h.attack("wall");

    std::cout << "\n--- FragTrap copy constructor ---" << std::endl;
    FragTrap i(g);
    i.attack("copy-test");

    std::cout << "\n--- FragTrap copy assignment ---" << std::endl;
    FragTrap j("Jill");
    j = g;
    j.attack("assign-test");

    std::cout << "\n--- ScavTrap and FragTrap are independent types ---" << std::endl;
    ScavTrap k("Kara");
    k.attack("wall");
    g.attack("wall");

    std::cout << "\n--- end of main ---" << std::endl;
    return 0;
}