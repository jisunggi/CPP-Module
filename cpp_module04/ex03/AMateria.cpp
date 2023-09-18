#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "AMateria";
}
      
AMateria::AMateria(std::string const &type)
{
    this->type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &amateria)
{
    this->type = amateria.getType();
}

AMateria &AMateria::operator=(const AMateria &amateria)
{
    if (this != &amateria)
		this->type = amateria.getType();
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