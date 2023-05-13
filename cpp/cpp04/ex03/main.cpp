#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	showLeaks()
{
	system("leaks --quiet ex03");
}


int main()
{
	atexit(showLeaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* ice;
	AMateria* cure;

	ice = src->createMateria("ice");
	me->equip(ice);
	cure = src->createMateria("cure");
	me->equip(cure);

	ICharacter* bob = new Character("bob");
	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;

	me->unequip(1);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	
	return 0;
}