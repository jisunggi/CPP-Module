#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;

    public:
		AMateria();
        AMateria(std::string const & type);
		~AMateria();
		AMateria(const AMateria &amateria);
		AMateria &operator=(const AMateria &amateria);
		
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif