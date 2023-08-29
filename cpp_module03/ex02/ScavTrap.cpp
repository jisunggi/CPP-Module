#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "noName";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap : constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	this->name = scavTrap.getName();
	this->hitPoints = scavTrap.getHitPoints();
	this->energyPoints = scavTrap.getEnergyPoints();
	this->attackDamage = scavTrap.getAttackDamage();
	std::cout << "ScavTrap : Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		this->name = scavTrap.getName();
		this->hitPoints = scavTrap.getHitPoints();
		this->energyPoints = scavTrap.getEnergyPoints();
		this->attackDamage = scavTrap.getAttackDamage();
	}
	std::cout << "ScavTrap : Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap became a gatekeeper" << std::endl;
}