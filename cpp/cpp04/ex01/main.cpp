#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
    meta->makeSound();

	std::cout << std::endl;

	std::cout << "Dog's idea: " << j->getIdea(0) << std::endl;
	std::cout << "Cat's idea: " << i->getIdea(0) << std::endl;
	std::cout << "Animal's idea: " << meta->getIdea(0) << std::endl;

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	system("leaks --quiet ex01");
}
