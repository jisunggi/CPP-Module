#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) 
:name(name), weapon(weapon)
{

}

void	HumanA::attack()
{
	std::string type = weapon.getType();
	std::cout << name << " attacks with their " << type << std::endl;
}