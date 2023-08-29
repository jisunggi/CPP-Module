#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap clapTrap;
	ScavTrap a;        
	ScavTrap b("b");
	ScavTrap c(a);     //복사생성자
	c = a;    //복사할당연산자


	std::cout << "-----------------------------" << std::endl;
	std::cout << clapTrap.getName() << " hit points : " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points : " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << clapTrap.getName() << " attack damage : " << clapTrap.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << a.getName() << " hit points : " << a.getHitPoints() << std::endl;
	std::cout << a.getName() << " energy points : " << a.getEnergyPoints() << std::endl;
	std::cout << a.getName() << " attack damage : " << a.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << b.getName() << " hit points : " << b.getHitPoints() << std::endl;
	std::cout << b.getName() << " energy points : " << b.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " attack damage : " << b.getAttackDamage() << std::endl;

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
	std::cout << clapTrap.getName() << " hit points : " << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getName() << " energy points : " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << clapTrap.getName() << " attack damage : " << clapTrap.getAttackDamage() << std::endl;

}