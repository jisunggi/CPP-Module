#include "Zombie.h"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << name;
    std::cout << " Zombie have been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name;
    std::cout << " Zombie is dead" << std::endl;

}

void Zombie::announce(void)
{
    std::cout << name << ": ";
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}