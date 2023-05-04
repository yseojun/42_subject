#include "Zombie.hpp"

void randomChump(std::string name);
Zombie	*newZombie(std::string name);

int main(void)
{
	Zombie	*z1;
	Zombie	hi;

	hi.announce();
	z1 = newZombie("Strong Zombie");
	z1->announce();
	delete z1;
	randomChump("Instance");
	return (0);
}