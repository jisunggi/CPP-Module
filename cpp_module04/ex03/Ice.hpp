#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif