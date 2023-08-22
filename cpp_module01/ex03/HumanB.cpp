#include "HumanB.h"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::string type = weapon->getType();
	std::cout << name << " attacks with their " << type << std::endl;
}