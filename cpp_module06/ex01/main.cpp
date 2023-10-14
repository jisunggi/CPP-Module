#include "Serializer.hpp"

int main (void)
{
    Data data;
    Data *dataPtr;
    uintptr_t unsignedIntPtr;

    data.name = "---empty---";
    std::cout << data.name << std::endl;
    unsignedIntPtr = Serializer::serialize(&data);
    std::cout << unsignedIntPtr << std::endl;

    dataPtr = Serializer::deserialize(unsignedIntPtr);
    std::cout << dataPtr->name << std::endl;

}