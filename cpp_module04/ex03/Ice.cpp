#include "Ice.hpp"

Ice::Ice()
{
    this->type = "Ice";
    std::cout << "Ice : Default constructor called" << std::endl;
}
      
Ice::Ice(std::string const &type)
{
    this->type = type;
    std::cout << "Ice type : constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice : Destructor called" << std::endl;
}

Ice::Ice(const Ice &ice)
{
    this->type = ice.getType();
    std::cout << "Ice : Copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &ice)
{
    if (this != &ice)
		this->type = ice.getType();
	std::cout << "Ice : Copy assignment operator called" << std::endl;
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
	std::cout << "* shoots an ice bolt at " << target.type << " *" << target.type << std::endl;
}