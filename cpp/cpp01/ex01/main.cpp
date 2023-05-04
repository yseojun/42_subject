#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int main(void)
{
	Zombie	*group;
	
	group = zombieHorde(3, "little zombie");
	for (int idx = 0; idx < 3; idx++)
		group[idx].announce();
	delete[] group;
}