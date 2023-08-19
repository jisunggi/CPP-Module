#include "Zombie.h"

Zombie::Zombie()
{
    std::cout << " Zombie have been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << " Zombie is dead" << std::endl;
}

void Zombie::setName(std::string)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << name << ": ";
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}