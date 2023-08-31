#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat : Destructor called" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	this->type = cat.getType();
	if (brain != NULL)
		delete brain;
	brain = new Brain(*cat.getBrain());
	std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->type = cat.getType();
		if (brain != NULL)
			delete brain;
		brain = new Brain(*cat.getBrain());
	}
	std::cout << "Cat : Copy assignment operator called" << std::endl;
	return *this;
}

Brain *Cat::getBrain() const
{
	return brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow 😺" << std::endl;
}