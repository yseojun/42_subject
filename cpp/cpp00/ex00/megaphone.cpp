#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int n = 1; n < ac; n++)
		{
			for (int idx = 0; av[n][idx]; idx++)
				std::cout << (char)std::toupper(av[n][idx]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
