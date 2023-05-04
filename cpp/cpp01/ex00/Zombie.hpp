#include <iostream>

class Zombie{
	public:

		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	announce();

	private:

		std::string name;

};