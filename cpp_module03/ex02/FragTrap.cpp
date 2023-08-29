#include "FragTrap.hpp"		
		
FragTrap::FragTrap()
{
	this->name = "noName FragTrap";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap : Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap : constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	this->name = fragTrap.getName();
	this->hitPoints = fragTrap.getHitPoints();
	this->energyPoints = fragTrap.getEnergyPoints();
	this->attackDamage = fragTrap.getAttackDamage();
	std::cout << "FragTrap : Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		this->name = fragTrap.getName();
		this->hitPoints = fragTrap.getHitPoints();
		this->energyPoints = fragTrap.getEnergyPoints();
		this->attackDamage = fragTrap.getAttackDamage();
	}
	std::cout << "FragTrap : Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "FragTrap can't do anything" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap does positive high five" << std::endl;
}