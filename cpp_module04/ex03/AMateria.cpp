#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "AMateria";
    std::cout << "AMateria : Default constructor called" << std::endl;
}
      
AMateria::AMateria(std::string const &type)
{
    this->type = type;
    std::cout << "AMateria type : constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria : Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &amateria)
{
    this->type = amateria.getType();
    std::cout << "AMateria : Copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
    if (this != &amateria)
		this->type = amateria.getType();
	std::cout << "AMateria : Copy assignment operator called" << std::endl;
	return *this;
}
		
std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << target.getName() << std::endl;
}