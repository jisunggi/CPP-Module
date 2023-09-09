#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
        MateriaSource(std::string const &name);
		~MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif