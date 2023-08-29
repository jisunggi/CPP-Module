#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap a;        //기본생성자
	ClapTrap b("b");   //오버로딩 생성자
	ClapTrap c(a);     //복사생성자
	c = a;    //복사할당연산자

	std::cout << "-----------------------------" << std::endl;
	std::cout << a.getName() << " hit points : " << a.getHitPoints() << std::endl;
	std::cout << a.getName() << " energy points : " << a.getEnergyPoints() << std::endl;
	std::cout << a.getName() << " attack damage : " << a.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << b.getName() << " hit points : " << b.getHitPoints() << std::endl;
	std::cout << b.getName() << " energy points : " << b.getEnergyPoints() << std::endl;
	std::cout << b.getName() << " attack damage : " << b.getAttackDamage() << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << c.getName() << " hit points : " << c.getHitPoints() << std::endl;
	std::cout << c.getName() << " energy points : " << c.getEnergyPoints() << std::endl;
	std::cout << c.getName() << " attack damage : " << c.getAttackDamage() << std::endl;

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
	for (int i = 0; i < 5; i++)
	{
		c.attack("abc");
		c.beRepaired(1);
	}
	c.takeDamage(15);
	c.beRepaired(1);
	std::cout << c.getName() << " hit points : " << c.getHitPoints() << std::endl;
	std::cout << c.getName() << " energy points : " << c.getEnergyPoints() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	
}