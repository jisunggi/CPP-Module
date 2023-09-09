#include "Character.hpp"

Character::Character()
{
    this->name = "Character";
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = 0;
	}
    std::cout << "Character : Default constructor called" << std::endl;
}

Character::Character(std::string const &name)
{
    this->name = name;
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = 0;
	}
    std::cout << "Character name : constructor called" << std::endl;
}

Character::~Character()
{
	for (int slot = 0; slot < 4; slot++)
		delete materias[slot];
    std::cout << "Character : Destructor called" << std::endl;
}

Character::Character(const Character &character)
{
    this->name = character.getName();
	for (int slot = 0; slot < 4; slot++)
	{
		if (materias[slot] != NULL)
			delete materias[slot];
	}
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = character.materias[slot];
	}
    std::cout << "Character : Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character)
{
    if (this != &character)
	{
		this->name = character.getName();
		for (int slot = 0; slot < 4; slot++)
		{
			if (materias[slot] != NULL)
				delete materias[slot];
		}
		for (int slot = 0; slot < 4; slot++)
		{
			materias[slot] = new AMateria();
			materias[slot] = character.materias[slot];
		}
	}
	std::cout << "Character : Copy assignment operator called" << std::endl;
	return *this;
}
		
std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int slot = 0; materias[slot]; slot++);
	if (slot > 3)
		return ;
	this->materias[slot] = *m;
}

void Character::unequip(int idx)
{
	if (materias[idx] == 0)
		return ;
	this->materias[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (materias[idx] == 0)
		return ;
	materias[idx]->use(target);
}