#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "noName";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	this->name = clapTrap.getName();
	this->hitPoints = clapTrap.getHitPoints();
	this->energyPoints = clapTrap.getEnergyPoints();
	this->attackDamage = clapTrap.getAttackDamage();
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this != &clapTrap)
	{
		this->name = clapTrap.getName();
		this->hitPoints = clapTrap.getHitPoints();
		this->energyPoints = clapTrap.getEnergyPoints();
		this->attackDamage = clapTrap.getAttackDamage();
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= amount)
	{
		std::cout << "ClapTrap died" << std::endl;
		hitPoints = 0;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << name << " take damage " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap can't do anything" << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << name << " be repaired " << amount << " points of damage!" << std::endl;
}