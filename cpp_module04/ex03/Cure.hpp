#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>

class Cure : public AMateria
{
    protected:
        std::string type;

    public:
		Cure();
		Cure(std::string const &type);
		~Cure();
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
		
        std::string const & getType() const; //Returns the materia type
        virtualCure* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif