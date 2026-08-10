#include "ClapTrap.hpp"

int main(void) {
    std::cout << "\n--- exact-zero boundary ---" << std::endl;
    ClapTrap h("Hank");
    h.takeDamage(10);
    h.takeDamage(1);

    std::cout << "\n--- dead but has energy: can it still attack? ---" << std::endl;
    ClapTrap i("Ivy");
    i.takeDamage(10);
    i.attack("wall");

    std::cout << "\n--- full health but no energy: can it repair? ---" << std::endl;
    ClapTrap j("Jack");
    for (int n = 0; n < 10; n++)
        j.attack("wall");
    j.beRepaired(5);

    std::cout << "\n--- taking exactly 0 damage ---" << std::endl;
    ClapTrap k("Kate");
    k.takeDamage(0);

    std::cout << "\n--- independence check ---" << std::endl;
    ClapTrap m("Mona");
    ClapTrap n("Nina");
    m.takeDamage(7);
    n.attack("wall");

    std::cout << "\n--- combined sequence ---" << std::endl;
    ClapTrap o("Oscar");
    o.attack("wall");
    o.takeDamage(4);
    o.beRepaired(2);

    return 0;
}