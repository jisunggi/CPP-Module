#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string);
        ~Zombie();
        void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif