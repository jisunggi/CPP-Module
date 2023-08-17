#include "Zombie.h"

Zombie *newZombie(std::string name)
{
    Zombie *heapZombie = new Zombie(name);

    return heapZombie;
}