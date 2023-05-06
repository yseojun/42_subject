#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon &something);
		void	attack(void);

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif