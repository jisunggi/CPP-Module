#include "Zombie.h"

int main ()
{
    Zombie *zombies;

    zombies = zombieHorde(5, "abc");
    for(int i = 0; i < 5; i++)
    {
        zombies[i].announce();
    }

    delete [] zombies;
}