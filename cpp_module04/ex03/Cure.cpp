#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    this->type = "cure";
}
      
Cure::Cure(std::string const &type) : AMateria(type)
{
    this->type = type;
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
    this->type = cure.getType();
}

Cure &Cure::operator=(const Cure &cure)
{
    if (this != &cure)
		this->type = cure.getType();
	return *this;
}
		
std::string const &Cure::getType() const
{
	return this->type;
}

Cure *Cure::clone() const
{
	Cure *cure = new Cure();
	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}