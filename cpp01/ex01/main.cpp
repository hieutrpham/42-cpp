#include "Zombie.hpp"

int main() {
	Zombie* zs = zombieHorde(3, "hieu");
	for (int i = 0; i < 3; i++)
		zs[i].announce();
	delete[] zs;
	return 0;
}
