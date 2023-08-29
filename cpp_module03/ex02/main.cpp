#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ScavTrap a;        
	ScavTrap b("b");
	ScavTrap c(a);
	c = a;

	FragTrap d;        
	FragTrap e("e");
	FragTrap f(d);
	f = d;

	std::cout << "-----------------------------" << std::endl;
	std::cout << a.getName() << " hit points : " << a.getHitPoints() << std::endl;
	std::cout << a.getName() << " energy points : " << a.getEnergyPoints() << std::endl;
	std::cout << a.getName() << " attack damage : " << a.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << b.getName() << " hit points : " << b.getHitPoints() << std::endl;
	std::cout << b.getName() << " energy points : " << b.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " attack damage : " << b.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << d.getName() << " hit points : " << d.getHitPoints() << std::endl;
	std::cout << d.getName() << " energy points : " << d.getEnergyPoints() << std::endl;
	std::cout << d.getName() << " attack damage : " << d.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << e.getName() << " hit points : " << e.getHitPoints() << std::endl;
	std::cout << e.getName() << " energy points : " << e.getEnergyPoints() << std::endl;
	std::cout << e.getName() << " attack damage : " << e.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	a.attack("abc");
	a.takeDamage(5);
	a.beRepaired(2);
	std::cout << a.getName() << " hit points : " << a.getHitPoints() << std::endl;
	std::cout << a.getName() << " energy points : " << a.getEnergyPoints() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	b.attack("abc");
	b.takeDamage(15);
	b.beRepaired(2);
	std::cout << b.getName() << " hit points : " << b.getHitPoints() << std::endl;
	std::cout << b.getName() << " energy points : " << b.getEnergyPoints() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	d.attack("abc");
	d.takeDamage(100);
	d.beRepaired(2);
	std::cout << d.getName() << " hit points : " << d.getHitPoints() << std::endl;
	std::cout << d.getName() << " energy points : " << d.getEnergyPoints() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	e.attack("abc");
	e.takeDamage(30);
	e.beRepaired(30);
	std::cout << e.getName() << " hit points : " << e.getHitPoints() << std::endl;
	std::cout << e.getName() << " energy points : " << e.getEnergyPoints() << std::endl;

}