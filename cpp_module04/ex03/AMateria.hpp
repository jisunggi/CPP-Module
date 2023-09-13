#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

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
		
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif