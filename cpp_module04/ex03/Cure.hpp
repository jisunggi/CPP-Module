#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

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
		
        std::string const & getType() const;
		Cure* clone() const;
        void use(ICharacter& target);
};

#endif