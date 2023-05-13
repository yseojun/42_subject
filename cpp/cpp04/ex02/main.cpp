#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	// A_Animal* k = A_Animal();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;

	std::cout << "Dog's idea: " << j->getIdea(0) << std::endl;
	std::cout << "Cat's idea: " << i->getIdea(0) << std::endl;

	std::cout << std::endl;

	delete j;
	delete i;

	system("leaks --quiet ex02");
}
