#include "Zombie.hpp"

void randomChump(std::string name);
Zombie	*newZombie(std::string name);

int main(void)
{
	Zombie	*strong;
	Zombie	normal;

	randomChump("Instance1");
	normal.announce();
	strong = newZombie("Strong Zombie");
	strong->announce();
	randomChump("Instance2");
	delete strong;
	return (0);
}