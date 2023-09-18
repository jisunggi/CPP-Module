#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    this->type = "ice";
}
      
Ice::Ice(std::string const &type) : AMateria(type)
{
    this->type = type;
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
    this->type = ice.getType();
}

Ice &Ice::operator=(const Ice &ice)
{
    if (this != &ice)
		this->type = ice.getType();
	return *this;
}
		
std::string const &Ice::getType() const
{
	return this->type;
}

Ice *Ice::clone() const
{
	Ice *ice = new Ice();
	return ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}