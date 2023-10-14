#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>

class  Serializer
{
    private :
        Serializer();
    
    public :
        ~Serializer();
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
