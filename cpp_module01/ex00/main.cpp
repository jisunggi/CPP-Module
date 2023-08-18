#include "Zombie.h"

int main ()
{
    Zombie *heapzombie = newZombie("heap");
	heapzombie->Zombie::announce();

	randomChump("stack");
	delete heapzombie;
}