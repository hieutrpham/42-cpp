#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0) {
		return nullptr;
	}
	Zombie *zs = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zs[i].setName(name);
	}
	return zs;
}
