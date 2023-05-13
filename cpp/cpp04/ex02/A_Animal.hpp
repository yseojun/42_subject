#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
 
class A_Animal
{
	protected:
		std::string type;

	public:
		A_Animal();
		A_Animal(std::string type);
		A_Animal(const A_Animal &copy);
		A_Animal	&operator=(const A_Animal &copy);
		virtual	~A_Animal();

		std::string			getType() const;
		virtual void		makeSound() const = 0;
		virtual std::string	getIdea(int i) const = 0;
};

#endif