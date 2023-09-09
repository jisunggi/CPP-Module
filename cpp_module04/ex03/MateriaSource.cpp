#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    this->name = "MateriaSource";
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = 0;
	}
    std::cout << "MateriaSource : Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(std::string const &name)
{
    this->name = name;
	for (int slot = 0; slot < 4; slot++)
	{
		materias[slot] = new AMateria();
		materias[slot] = 0;
	}
    std::cout << "MateriaSource name : constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int slot = 0; slot < 4; slot++)
		delete materias[slot];
    std::cout << "MateriaSource : Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    this->name = MateriaSource.getName();
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
    if (this != &MateriaSource)
	{
		this->name = MateriaSource.getName();
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
		
std::string const &MateriaSource::getName() const
{
	return this->name;
}

void MateriaSource::equip(AMateria *m)
{
	for (int slot = 0; materias[slot]; slot++);
	if (slot > 3)
		return ;
	this->materias[slot] = *m;
}

void MateriaSource::unequip(int idx)
{
	if (materias[idx] == 0)
		return ;
	this->materias[idx] = 0;
}

void MateriaSource::use(int idx, IMateriaSource& target)
{
	if (materias[idx] == 0)
		return ;
	materias[idx]->use(target);
}