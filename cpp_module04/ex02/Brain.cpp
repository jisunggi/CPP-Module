#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "[[empty]]";
	}
	std::cout << "Brain : Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = brain.ideas[i];
	}
	std::cout << "Brain : Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = brain.ideas[i];
		}
	}
	std::cout << "Brain : Copy assignment operator called" << std::endl;
	return *this;
}

std::string Brain::getIdea(int n) const
{
	return this->ideas[n];
}

void Brain::setIdea(int n, std::string string)
{
	this->ideas[n] = string;
}