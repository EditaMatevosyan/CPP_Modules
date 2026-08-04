#include "Zombie.hpp"

int main() {
    for (int i = 0; i < 5; ++i) {
        Zombie* zombie = newZombie("Zombie" + std::to_string(i + 1));
        zombie->announce();
        delete zombie;
    }
    randomChump("Zombie2");

    return 0;
}
