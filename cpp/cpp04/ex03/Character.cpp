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
};

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
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
	this->inventory[idx] = NULL;
};

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
};