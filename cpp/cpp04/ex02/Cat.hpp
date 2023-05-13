#ifndef CAT_HPP
# define CAT_HPP

# include "A_Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal
{
	private: 
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat();

		void		makeSound() const;
		std::string	getIdea(int i) const;
};

#endif