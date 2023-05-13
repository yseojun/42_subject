#include "Character.hpp"

Character::Character() : name("default"){
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
};

Character::Character(std::string const & name) : name(name){
	std::cout << "Character parametric constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
};

Character::Character(Character const & src){
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	for(int i = 0; i < 4; i++)
		if (src.inventory[i] != NULL)
			delete this->inventory[i];
	for(int i = 0; i < 4; i++)
		if (src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
};

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
};

Character	&Character::operator=(Character const & rhs){
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &rhs){
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			if (rhs.inventory[i] != NULL)
				this->inventory[i] = rhs.inventory[i]->clone();
	}
	return *this;
};

std::string const & Character::getName() const{
	return this->name;
};

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
};

void	Character::unequip(int idx){
	if (idx < 0 || idx > 3)
		return ;
	std::cout << "Unequipped " << this->inventory[idx]->getType() << std::endl;
	this->inventory[idx] = NULL;
};

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	else if (this->inventory[idx] == NULL)
	{
		std::cout << "No materia at this index" << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
};