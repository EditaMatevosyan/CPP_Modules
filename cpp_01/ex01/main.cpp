#include "Zombie.hpp"

int main() {
    std::string	name;

	std::cout << "Name for horde: ";
	std::cin >> name;

	int	N;

	std::cout << "Num of zombies: ";
	std::cin >> N;

	Zombie*	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);
}
