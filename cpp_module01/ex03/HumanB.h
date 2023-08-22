#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.h"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
		
	public:
		HumanB(std::string);
		void	setWeapon(Weapon &weapon);
		void	attack();

};

#endif