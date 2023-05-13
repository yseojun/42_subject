#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*save[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const & rhs);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif