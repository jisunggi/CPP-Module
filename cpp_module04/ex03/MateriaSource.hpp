#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[4];
	
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
		void deleteMateriaInventory();
};

#endif