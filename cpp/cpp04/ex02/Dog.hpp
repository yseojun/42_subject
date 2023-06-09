#ifndef DOG_HPP
# define DOG_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog();
		
		void		makeSound() const;
		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string idea);
};

#endif