#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = 0;
}

MateriaSource::~MateriaSource()
{
	deleteMateriaInventory();
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	for (int slot = 0; slot < 4; slot++)
	{
		if (materias[slot] != NULL)
			deleteMateriaInventory();
	}
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = materiaSource.materias[slot]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if (this != &materiaSource)
	{
		for (int slot = 0; slot < 4; slot++)
		{
			if (materias[slot] != NULL)
				deleteMateriaInventory();
		}
		for (int slot = 0; slot < 4; slot++)
			materias[slot] = materiaSource.materias[slot]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int slot;

	for (slot = 0; materias[slot]; slot++);
	if (slot > 3)
		return ;
	this->materias[slot] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (!(type == "ice" || type == "cure"))
		return 0;
	for (int slot = 0; materias[slot]; slot++)
	{
		if (materias[slot]->getType() == type)
			return materias[slot]->clone();
	}
	return 0;
}

void	MateriaSource::deleteMateriaInventory()
{
	for (int slot = 0; slot < 4; slot++)
		delete materias[slot];
}