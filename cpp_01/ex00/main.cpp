#include "Zombie.hpp"

int main() {
    Zombie* some_zombie = newZombie("Zombie1");

	some_zombie->announce();
	delete some_zombie;

    randomChump("Zombie2");

    return 0;
}
