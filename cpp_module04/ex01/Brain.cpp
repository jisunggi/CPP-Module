#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain : Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
			this->type = cat.getType();
	}
	std::cout << "Brain : Copy assignment operator called" << std::endl;
	return *this;
}