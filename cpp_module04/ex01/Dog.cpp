#include "Dog.hpp"

Dog::Dog()
{
	brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog : Destructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->type = dog.getType();
	std::cout << "Dog : Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
			this->type = dog.getType();
	}
	std::cout << "Dog : Copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark 🐶" << std::endl;
}