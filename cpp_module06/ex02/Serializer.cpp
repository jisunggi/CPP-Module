#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer : Default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer : Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &serializer)
{
    (void)&serializer;
	std::cout << "Serializer : Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &serializer)
{
	if (this != &serializer)
	{
        std::cout << "Serializer : Copy assignment operator called" << std::endl;
	    return *this;
	}
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}