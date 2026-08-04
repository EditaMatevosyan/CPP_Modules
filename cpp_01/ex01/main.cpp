#include "Zombie.hpp"

int main() {
    Zombie* zombies = zombieHorde(6, "sari smbul");
    delete[] zombies;
    return 0;
}
