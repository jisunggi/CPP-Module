#include "Cure.hpp"

Cure::Cure()
{
    this->type = "Cure";
    std::cout << "Cure : Default constructor called" << std::endl;
}
      
Cure::Cure(std::string const &type)
{
    this->type = type;
    std::cout << "Cure type : constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure : Destructor called" << std::endl;
}

Cure::Cure(const Cure &cure)
{
    this->type = cure.getType();
    std::cout << "Cure : Copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &cure)
{
    if (this != &cure)
		this->type = cure.getType();
	std::cout << "Cure : Copy assignment operator called" << std::endl;
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
	std::cout << "* heals " << target->name << "'s wounds *" << std::endl;
}