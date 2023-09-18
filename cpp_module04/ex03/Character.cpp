#include "Character.hpp"

Character::Character()
{
    this->name = "Character";
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = 0;
}

Character::Character(std::string const &name)
{
    this->name = name;
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = 0;
}

Character::~Character()
{
	deleteMateriaInventory();
}

Character::Character(const Character &character)
{
    this->name = character.getName();
	for (int slot = 0; slot < 4; slot++)
	{
		if (materias[slot] != NULL)
			deleteMateriaInventory();
	}
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = character.materias[slot]->clone();
}

Character &Character::operator=(const Character &character)
{
    if (this != &character)
	{
		this->name = character.getName();
		for (int slot = 0; slot < 4; slot++)
		{
			if (materias[slot] != NULL)
				deleteMateriaInventory();
		}
		for (int slot = 0; slot < 4; slot++)
			materias[slot] = character.materias[slot]->clone();
	}
	return *this;
}

void	Character::deleteMateriaInventory()
{
	for (int slot = 0; slot < 4; slot++)
		delete materias[slot];
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	int slot;
	for (slot = 0; materias[slot]; slot++);
	if (slot > 3)
		return ;
	this->materias[slot] = m;
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
	{
		return ;
	}
	materias[idx]->use(target);
}