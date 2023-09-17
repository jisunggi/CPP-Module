#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int slot = 0; slot < 4; slot++)
		materias[slot] = 0;
    std::cout << "MateriaSource : Default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	deleteMateriaInventory();
    std::cout << "MateriaSource : Destructor called" << std::endl;
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
    std::cout << "MateriaSource : Copy constructor called" << std::endl;
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
	std::cout << "MateriaSource : Copy assignment operator called" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int slot;

	for (slot = 0; materias[slot]; slot++);
	if (slot > 3)
		return ;
	std::cout << m->getType() << std::endl;
	this->materias[slot] = m;
	std::cout << materias[slot]->getType() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (!(type == "ice" || type == "cure"))
	{
		std::cout << "aaa" << std::endl;
		return 0;
	}
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