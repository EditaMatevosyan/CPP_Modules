#include "Zombie.hpp"

int main() {
    std::string	name;

	std::cout << "Name for horde: ";
	std::cin >> name;

	int	N = 0;

	std::cout << "Num of zombies: ";
	if (!(std::cin >> N) || N <= 0) {
		std::cerr << "Invalid number of zombies." << std::endl;
		return 1;
	}

	Zombie*	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);
}
