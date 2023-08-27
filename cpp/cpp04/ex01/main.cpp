#include "Dog.hpp"
#include "Cat.hpp"

void	showLeaks()
{
	system("leaks --quiet ex01");
}

int main()
{
	atexit(showLeaks);
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	Animal* j = new Dog();
	Animal *test_dog = new Dog();

	*test_dog = *j;

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

	test_dog->setIdea(0, "I'm a dog!");
	std::cout << "Test dog's idea: " << test_dog->getIdea(0) << std::endl;
	std::cout << "Dog's idea: " << j->getIdea(0) << std::endl;

	std::cout << std::endl;

	Dog A;
	Dog B = A;

	delete meta;
	delete j;
	delete i;
	delete test_dog;
}
