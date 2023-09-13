#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = 0;
	}
    std::cout << "MateriaSource : Default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int slot = 0; slot < 4; slot++)
		delete materias[slot];
    std::cout << "MateriaSource : Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	for (int slot = 0; slot < 4; slot++)
	{
		if (materias[slot] != NULL)
			delete materias[slot];
	}
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = MateriaSource.materias[slot];
	}
    std::cout << "MateriaSource : Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if (this != &materiaSource)
	{
		for (int slot = 0; slot < 4; slot++)
		{
			if (materias[slot] != NULL)
				delete materias[slot];
		}
		for (int slot = 0; slot < 4; slot++)
		{
			materias[slot] = new AMateria();
			materias[slot] = MateriaSource.materias[slot];
		}
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
	this->materias[slot] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (!(type == "ice" || type == "cure"))
		return 0;
	for (int slot = 0; materias[slot]; slot++)
	{
		if (materias[slot]->type == "type")
			return materias[slot]->clone();
	}
	return 0;
}