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

#endif