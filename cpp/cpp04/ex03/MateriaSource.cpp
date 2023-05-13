#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource parametric constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->save[i] = NULL;
};

MateriaSource::MateriaSource(MateriaSource const & src){
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
};

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->save[i] != NULL)
			delete this->save[i];
};

MateriaSource	&MateriaSource::operator=(MateriaSource const & rhs){
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &rhs){
		for (int i = 0; i < 4; i++)
			if (this->save[i] != NULL)
				delete this->save[i];
		for (int i = 0; i < 4; i++)
			if (rhs.save[i] != NULL)
				this->save[i] = rhs.save[i]->clone();
	}
	return *this;
};

void	MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (this->save[i] == NULL)
		{
			this->save[i] = m;
			return ;
		}
	}
};

AMateria	*MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (this->save[i] != NULL && this->save[i]->getType() == type)
			return this->save[i]->clone();
	}
	return NULL;
};