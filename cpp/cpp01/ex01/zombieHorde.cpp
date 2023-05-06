#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*group = new Zombie[N];

	for (int idx = 0; idx < N; idx++)
		group[idx].setName(name + "_" + std::to_string(idx));

	return (group);
}
