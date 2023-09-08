#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>

class Ice : public AMAteria
{
    protected:
        std::string type;

    public:
		Ice();
        Ice(std::string const & type);
		~Ice();
		Ice(const Ice &amateria);
		Ice &operator=(const Ice &amateria);
	
        std::string const & getType() const;
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif